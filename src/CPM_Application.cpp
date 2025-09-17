//CPM Includes:
#include <CPM/CPM_Application.h>
#include <CPM/CPM_Command.h>
#include <CPM/CPM_Registry.h>
#include <CPM/CPM_Settings.h>

//C++ Includes:
#include <iostream>

namespace CPM{


int Application::run(int argc, char* argv[]) {
    for(int i = 0; i < argc; ++i) {
        std::cout<<"Argument "<<i<<": "<<argv[i]<<"\n";
    }
    if(argc < 2) {
        std::cout<<"No Arguments Given! TODO: Implement CPM::UI::DefaultMessage()\n";
        return 0;
    }

    try {
        std::unique_ptr<Command> command = Registry<Command>::Create(argv[1]);
        command->execute();

    } catch (const std::exception& e) {
        std::cout<<"Error: "<<e.what()<<"\n";
        return -1;
    } catch (...) {
        std::cout<<"Unknown Error\n";
        return -1;
    }

    return 0;
} 


void Application::initialize() {

}

void Application::cleanup() {

}

void Application::handleError() {

}



}