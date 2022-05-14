#include "thread.h"

__BEGIN_API
// Declaração inicial do uid das threads
int Thread::uid = 0;
// Declaração inicial do ponteiro que aponta para thread
// que está rodando
Thread* Thread::_running = nullptr;

void Thread::thread_exit(int exit_code) {
    //Implementação da destruição da thread
    delete this->_context;
}

/*
* Retorna o id de uma thread em específico
*/
int Thread::id() {
    return this->_id;
}

__END_API