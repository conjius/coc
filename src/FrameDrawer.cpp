#include "FrameDrawer.h"

#include <raylib.h>
#include <filesystem>

using std::min;
namespace fs = std::filesystem;

FrameDrawer::FrameDrawer(const int& width, const int& height, const GameState& state)
    : width(width), height(height), state(state) {
}

// — point‑in‑polygon winding test (ray crossing) ————————————————
bool FrameDrawer::PointInPoly(const Vector2* vertices, const int count,
                              const Vector2 p) const {
    bool inside = false;
    for (int i = 0, j = count - 1; i < count; j = i++) {
        const Vector2 &vi = vertices[i], &vj = vertices[j];
        const bool intersect = ((vi.y > p.y) != (vj.y > p.y)) &&
            (p.x < (vj.x - vi.x) * (p.y - vi.y) / (vj.y - vi.y) + vi.x);
        if (intersect) inside = !inside;
    }
    return inside;
}

void FrameDrawer::drawGameState(const GameState& state) const {
    vector<Texture2D> tileTextures;
    for (auto const& entry : fs::directory_iterator("assets/hexes")) {
        if (!entry.is_regular_file()) continue;
        auto ext = entry.path().extension().string();
        if (!(ext == ".png" || ext == ".jpg" || ext == ".bmp")) continue;

        // 1) Load into CPU RAM
        Image img = LoadImage(entry.path().string().c_str());
        ImageFormat(&img, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);

        // 2) Compute hexagon polygon in image-space
        int width = img.width, height = img.height;
        Vector2 hex[6];
        const double radius = min(width, height) * 0.5l;
        const Vector2 centerImg = {width * 0.5f, height * 0.5f};
        for (int i = 0; i < 6; i++) {
            const float angle = DEG2RAD * (30 + 60 * i);
            hex[i] = {
                centerImg.x + cosf(angle) * radius,
                centerImg.y + sinf(angle) * radius
            };
        }

        // 3) Mask away pixels outside the hexagon
        auto* px = static_cast<Color*>(img.data);
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (!PointInPoly(hex, 6, {
                                     static_cast<float>(x), static_cast<float>(y)
                                 })) {
                    px[y * width + x].a = 0;
                }
            }
        }

        // 4) Rotate the masked image 90° clockwise so its axes align with your flat‑topped grid
        ImageRotateCW(&img); // Rotate image clockwise 90°

        // 5) Upload to GPU and free CPU image
        Texture2D tex = LoadTextureFromImage(img);
        UnloadImage(img);
        tileTextures.push_back(tex);
    }

    // — Hex grid parameters ————————————————————————————————
    constexpr double R = 30.0f;
    const double Hstep = sqrtf(3.0l) * R;
    constexpr double Xstep = 1.5l * R;
    constexpr int cols = static_cast<int>(this->width / Xstep) + 2;
    const int rows = static_cast<int>(this->height / Hstep) + 2;

    // — Precompute a fixed random texture index for each cell ————————
    vector gridTex(cols, vector(rows, -1));
    for (int c = 0; c < cols; c++) {
        for (int r = 0; r < rows; r++) {
            if (!tileTextures.empty()) {
                gridTex[c][r] = rand() % tileTextures.size();
            }
        }
    }
}
