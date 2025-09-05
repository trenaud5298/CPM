#ifndef CPM_COMMAND_H
#define CPM_COMMAND_H

#include <string>
#include <functional>
#include <map>

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
        virtual void loadArguments(int argc, char** argv) = 0;

        //Executes Command
        virtual int execute() = 0;


    protected:
        //Register A New Command With The Main Command Registry By Reference And Constructor Function
        static bool registerCommand(const std::string& reference, std::function<Command*()> constructor);

    private:
        // Provides A Singular Static Registry Instance Created On First Call
        static std::map<std::string, std::function<Command*()>>& registry();
    };


};

#endif