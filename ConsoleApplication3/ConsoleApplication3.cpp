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
    cout << "esty";
    cout << "esty and racheli";
    cout <<"hello world from Rachely"
    Game game;
    game.handleUserInput();
    game._world();
   /* game._start();*/
    game._asserts();
    cout << game;
    cout << "my try 1";
    
   // Input i;
   // i.parse_and_store();
   // vector<string> asserts = i.asserts;
   // auto steps = i.steps;
   // const Command& cmd = *(i.world);

   // vector<int> typeTiles;
   // for (const auto& row : cmd.data) {
   //     for (const auto& item : row) {
   //         typeTiles.push_back(std::stoi(item));
   //     }
   // }
   // int y = cmd.data.size();
   // int x = typeTiles.size() / y;

   // World w(typeTiles, x, y);

   // int locationX = stoi((i.steps)[0]->arguments[0]);
   // int locationY = stoi((i.steps)[0]->arguments[1]);
   // for (string assert : asserts)
   // {
   //     string command = assert;
   //     if (command == "SelectedCategory")
   //         cout << "SelectedCategory " << w.getTileType(locationX, locationY);
   // }
   ///* cout << "-----------------------"<<endl;
   // for (auto& c_ptr : i.steps)
   // {
   //         cout << *c_ptr;
   // }
   // cout <<"strt" << endl;*/

   // for (auto& c_ptr : i.start)
   // {

   //         cout << *c_ptr;
   // }

   // cout << endl;
   // return 0;
}

