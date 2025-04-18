#pragma once
#include <string>
#include <utility>


class Player;
using std::string;

class Unit {
public:
    Unit(string  id, const Player& player)
        : id(std::move(id)),
          player(player) {
    }

private:
    string id;
    const Player& player;
};
