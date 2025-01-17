#include "Command.h"
#include <iostream>
using namespace std;
const std::string Command::WORLD = "World";
const std::string Command::START = "Start";
const std::string Command::INPUT = "Input";
const std::string Command::ASSERTS = "Asserts";

const std::string Command::WAIT = "Wait";

const std::string Command::SELECT = "Select";
const std::string Command::MOVE = "Move";
const std::string Command::WORK = "Work";
const std::string Command::DEPOSIT = "Deposit";
const std::string Command::TAKE_RESOURCES = "TakeResources";
const std::string Command::BUILD = "Build";
const std::string Command::MANUFACTURE = "Manufacture";
const std::string Command::PEOPLE = "People";
const std::string Command::RESOURCE = "Resource";
const std::string Command::RESOURCES = "Resources";
const std::string Command::MAKE_EMPTY = "MakeEmpty";
const std::string Command::RAIN = "Rain";
const std::string Command::ROBBER = "Robber";
const std::string Command::MAKE_ROBBER = "MakeRobber";

const int Command::N_RESOURCES = 4;

ostream& operator<<(std::ostream& os, const Command& cmd)
{


    os << "Command: " << cmd.name << "\nArguments: ";
    for (const auto& arg : cmd.arguments) {
        os << arg << " ";
    }
    os << "\n+World:\n";
    for (const auto& row : cmd.data) {
        for (const auto& item : row) {
            os << item << " ";
        }
        os << "\n";
    }
    return os;

}