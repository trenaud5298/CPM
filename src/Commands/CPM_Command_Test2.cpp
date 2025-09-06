#include <CPM/CPM_Command.h>
#include <CPM/CPM_Registry.h>

#include <iostream>

namespace CPM {
    class CommandTest2 : public Command {
    
    public:
        std::string reference() const override {
            return "Test2";
        }

        std::string description() const override {
            return "Test2's Description";
        }

        void loadArguments(int* argc, char** argv) {
            return;
        }

        int execute() {
            std::cout<<"Executing Test2\n";
            return 0;
        }
    
    private:
        REGISTER_TYPE(Command, CommandTest2, "Test2");
    };
}