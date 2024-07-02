#include "Game.h"

void Game::_start()
{
 auto start= (input->start);
 /*for (auto& c_ptr : start)
 {
     if (c_ptr->name == "Resource") {
         int amount = stoi(c_ptr->arguments[0]);
         string typeResource = c_ptr->arguments[1];
         int locationX = stoi(c_ptr->arguments[2]);
         int locationY = stoi(c_ptr->arguments[3]);
         Tile tile = world->selectTile(locationX, locationY);
         tile.increaseResources(amount, typeResource);
         double* e= new double[4];
          e=tile.getResourses();
          output = "SelectedResource ";
          std::ostringstream oss;
          for (int i = 0; i < 4; i++) {
              oss << e[i];
              if (i < 3) {
                  oss << ' ';
              }
          }
          output += oss.str();
         if (e != nullptr)
             delete[] e;
         
     }
 }*/
}

void Game::_world()
{
    const Command& cmd = *(input->world);

    vector<int> typeTiles;
    for (const auto& row : cmd.data) {
        for (const auto& item : row) {
            typeTiles.push_back(std::stoi(item));
        }
    }
    int y = cmd.data.size();
    int x = typeTiles.size() / y;

    world = new World(typeTiles, x, y);
}

void Game::_input()
{
    
}

void Game::_asserts()
{
    int locationX = stoi((input->steps)[0]->arguments[0]);
    int locationY = stoi((input->steps)[0]->arguments[1]);
    for (string assert : input->asserts)
    {
        string command = assert;
        if (command == "SelectedCategory")
           output = "SelectedCategory " + world->getTileType(locationX, locationY);
    }
}

void Game::handleUserInput()
{
	input = new Input;
    input->parse_and_store();
}
Game::~Game()
{
}
ostream& operator<<(std::ostream& os, const Game& game)
{
    os << game.output;  
    return os;

}