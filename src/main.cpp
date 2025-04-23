#include <memory>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <filesystem>

#include "FrameDrawer.h"
#include "raylib.h"
#include "Game.h"
#include "core/GameManager.h"

namespace fs = std::filesystem;
using std::min;
using std::vector;
using std::unique_ptr;
using std::make_unique;

#define WINDOW_WIDTH   500
#define WINDOW_HEIGHT  500

int main() {
    constexpr GameManager gameManager;
    gameManager.init();
    gameManager.start();
    gameManager.cleanup();
    return 0;
}
