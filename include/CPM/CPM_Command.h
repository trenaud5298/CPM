#ifndef CPM_COMMAND_H
#define CPM_COMMAND_H

//CPM Includes:

//C++ Includes:
#include <string>
#include <functional>
#include <map>
#include <memory>

namespace CPM {

    class Command {
    public:
        //Ensures Child Class Destructor Is Porperly Called
        virtual ~Command() = default;

        //Returns The Unique Reference Keyword That Refers To A Specific Command
        virtual std::string reference() const = 0;

        //Returns A Description Of The Specific Command
        virtual std::string description() const = 0;

        //Loads Arguments Into Command
        virtual void loadArguments(int* argc, char** argv) = 0;

        //Executes Command
        virtual int execute() = 0;

    };
};

#endif