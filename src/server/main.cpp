#include "Application.h"

#include <iostream>
#include "signal.h"

void sigPipeHandler(int signum) {
    std::cerr<<"SIGPIPE"<<std::endl;
}

int main()
 {
    if(signal(SIGPIPE, sigPipeHandler) == SIG_ERR) {
        std::cerr<<"Fail to handler SIGPIPE"<<std::endl;
    }

    einheri::Application application;

    application.Run();


     return EXIT_SUCCESS;

 }


