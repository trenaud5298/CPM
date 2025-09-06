#ifndef CPM_COMMAND_MODIFIER
#define CPM_COMMAND_MODIFIER

//CPM Includes:

//C++ Includes:
#include <string>
#include <vector>

namespace CPM {
    struct CommandModifier {
        std::string flag;
        std::vector<std::string> values;
    };
}

#endif