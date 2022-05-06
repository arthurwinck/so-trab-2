#include "thread.h"

__BEGIN_API

//Implementação do Construtor
template<typename ... Tn>
Thread::Thread(void (* entry)(Tn ...), Tn ... an) {};




__END_API