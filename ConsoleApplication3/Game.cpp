#include "Game.h"

void Game::_start()
{
 vector< shared_ptr<Command>> start= (input->start);

 for (auto cmd : start)
 {
     

    
     if (cmd->name == Command::RESOURCE) {
         //Handle input 
         int amount = stoi(cmd->arguments[0]);
         string typeResource = cmd->arguments[1];
         int locationX = stoi(cmd->arguments[2]);
         int locationY = stoi(cmd->arguments[3]);

         Tile* tile = world-> selectTile(locationX, locationY);
         tile->increaseResources(amount, typeResource);
         double* resourses = new double[Command::N_RESOURCES];
         resourses = tile->getResourses();
         //Set output
         output = "SelectedResource ";
         std::ostringstream oss;
         for (int i = 0; i < 4; i++) {
              oss << resourses[i];
              if (i < 3) {
                  oss << ' ';
              }
         }

         output += oss.str();
          //Free memory alocation
         if (resourses != nullptr)
             delete[] resourses;
     }
 }
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