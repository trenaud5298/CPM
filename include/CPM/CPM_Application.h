#ifndef CPM_APPLICATION_H
#define CPM_APPLICATION_H

namespace CPM {

class Application {

public:
    static int run(int argc, char* argv[]);

private:
    static void initialize();
    static void cleanup();
    static void handleError();
};


}

#endif