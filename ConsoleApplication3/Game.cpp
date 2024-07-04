#include "Game.h"
#include "GameUtility.h"

void Game::_start()
{
	vector< shared_ptr<Command>> start = (input->start);

	for (auto cmd : start)
	{
		if (cmd->name == Command::RESOURCE) {
			//Handle input 
			int amount = stoi(cmd->arguments[0]);
			string typeResource = cmd->arguments[1];
			int locationX = stoi(cmd->arguments[2]);
			int locationY = stoi(cmd->arguments[3]);

			Tile* tile = world->selectTile(locationX, locationY);
			tile->increaseResources(amount, typeResource);
		}
		else if (cmd->name == Command::PEOPLE) {
			int amount = stoi(cmd->arguments[0]);
			int locationX = stoi(cmd->arguments[1]);
			int locationY = stoi(cmd->arguments[2]);
			world->addPerson(locationX, locationY);
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
	const auto& commands = input->steps;
	for (auto cmd : commands) {
		if (cmd->name == Command::SELECT) {
			int locationX = stoi(cmd->arguments[0]);
			int locationY = stoi(cmd->arguments[1]);
			selectedCell = world->selectCell(locationX, locationY);
		}
		else if (cmd->name == Command::WORK) {
			int locationX = stoi(cmd->arguments[0]);
			int locationY = stoi(cmd->arguments[1]);
			//Person* p = static_cast<Person*>(selectedCell.getGround().get());
			function<void()> work;
			
			work = bind(GameUtility::work, world->selectCell(locationX, locationY));
			
			progressFuncs.emplace_back(work);

		}
		else if (cmd->name == Command::WAIT) {
			for (auto f : progressFuncs) {
				f();
			}

		}
	}
}

void Game::_asserts()
{

	for (string assert : input->asserts)
	{
		string command = assert;
		if (command == "SelectedCategory") {
			output = "SelectedCategory " + world->getTileType(selectedCell);
		}
		else if (command == "SelectedResource") {
			double* resourses = new double[Command::N_RESOURCES];
			resourses = selectedCell.getBlock()->getResourses();
			//Set output
			output = "SelectedResource  ";
			std::ostringstream oss;
			for (int i = 0; i < Command::N_RESOURCES; i++) {
				oss << resourses[i];
				if (i < Command::N_RESOURCES - 1) {
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