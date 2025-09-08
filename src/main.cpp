#include <iostream>
#include <CPM/CPM_Application.h>

int main(int argc, char* argv[]) {
    std::cout<<"In main func\n";
    return CPM::Application::run(argc, argv);
}