#include "thread.h"

__BEGIN_API

void Thread::thread_exit(int exit_code) {
    //Implementação da destruição da thread
    Thread::_running = NULL;
    delete this->_context;

}

__END_API