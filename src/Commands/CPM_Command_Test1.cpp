#include <CPM/CPM_Command.h>
#include <CPM/CPM_Registry.h>

#include <iostream>

namespace CPM {
    class CommandTest1 : public Command {
    
    public:
        std::string reference() const override {
            return "Test1";
        }

        std::string description() const override {
            return "Test1's Description";
        }

        void loadArguments(int* argc, char** argv) {
            return;
        }

        int execute() {
            std::cout<<"Executing Test1\n";
            return 0;
        }
    
    private:
        REGISTER_TYPE(Command, CommandTest1, "Test1");
    };
}