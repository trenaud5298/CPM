#include <iostream>
#include <CPM/CPM.h>

int main(int* argc, char** argv) {
    std::cout<<"In main func\n";

    auto it = CPM::Registry<CPM::Command>::keys();
    for(auto a : it) {
        std::cout<<a<<"\n";
    }
    std::unique_ptr<CPM::Command> c1 = CPM::Registry<CPM::Command>::create("Test1");
    std::unique_ptr<CPM::Command> c2 = CPM::Registry<CPM::Command>::create("Test2");

    c1->execute();
    c2->execute();
}