#include "JsonHandler.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

JsonHandler::JsonHandler(string configPath) {
    // Open and read the JSON config file
    ifs.open(configPath);
    if (!ifs.is_open()) {
        throw runtime_error("Failed to open configuration json file: " + configPath);
    }
    // Parse the JSON file
    ifs >> config;

}
//read the JSON config file
json JsonHandler::read()
{
    return config;
}
// closethe JSON config file
JsonHandler::~JsonHandler()
{
    if (ifs.is_open()) {
        ifs.close();
    }
}
