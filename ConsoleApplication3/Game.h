#pragma once
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
using namespace std;
using json = nlohmann::json;

class Game
{
private:
	Input* input;
	World* world;
	string output="";

public:
	void _start();
	void _world();
	void _input();
	void _asserts();


	void handleUserInput();
	friend std::ostream& operator<<(std::ostream& os, const Game& game);
	~Game();

};

