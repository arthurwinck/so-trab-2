#include "thread.h"

__BEGIN_API
int Thread::uid = 0;


void Thread::thread_exit(int exit_code) {
    //Implementação da destruição da thread
    Thread::_running = NULL;
    delete this->_context;
    
}

/*
* Retorna o id de uma thread em específico
*/
int Thread::id() {
    return this->_id;
}

__END_API