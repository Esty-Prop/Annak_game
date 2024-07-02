#pragma once
#include <fstream>
#include <sstream>
#include "json.hpp"
#include <string>
using namespace std;
using json = nlohmann::json;
class JsonHandler
{
private:

	json config;
	ifstream ifs;

public:
	JsonHandler(string configPath);
	json read();
	~JsonHandler();

};



