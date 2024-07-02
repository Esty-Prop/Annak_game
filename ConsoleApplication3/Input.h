#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Command.h"

class Input
{

    // Private methods
    void start_lines();
    std::string next_line();
public:
    // Constructor
    Input()
    {
        world.reset(new Command(Command::WORLD));
    }
    // Public methods
    void parse_and_store();
    // Public members
    std::shared_ptr<Command> world;
    std::vector< std::shared_ptr<Command> > start;
    std::vector< std::shared_ptr<Command> > steps;
    std::vector<std::string> asserts;
    std::vector<int> typeTiles;
    // Static method
    static std::shared_ptr<Command> parse_command(std::string line);
};

