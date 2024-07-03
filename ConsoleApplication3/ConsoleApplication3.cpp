#include <iostream>
#include "Input.h"
#include "Command.h"
#include "Utility.h"
#include "json.hpp"
#include <string>
#include <fstream>
#include <vector>
#include "World.h"
#include "Tile.h"
#include "Game.h"

using namespace std;
using json = nlohmann::json;


int main() {
    Game game;
    game.handleUserInput();
    game._world();
    game._start();
    //game._asserts();
    cout << game;
};
