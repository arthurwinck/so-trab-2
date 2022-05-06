#ifndef cpu_h
#define cpu_h

#include <ucontext.h>
#include <iostream>
#include "traits.h"

__BEGIN_API

class CPU
{
    public:

        class Context
        {
        private:
            static const unsigned int STACK_SIZE = Traits<CPU>::STACK_SIZE;
        public:
            Context() { _stack = 0; }

            template<typename ... Tn>
            Context(void (* func)(Tn ...), Tn ... an);

            ~Context();

            void save();
            void load();

        private:            
            char *_stack;
        public:
            ucontext_t _context;
        };

    public:

        static void switch_context(Context *from, Context *to);

};

//Construtor da classe usando variadic templates
template<typename ... Tn>
CPU::Context::Context(void (* func)(Tn ...), Tn ... an) {
    //Criação de um contexto nulo
    ucontext_t u_context;
    save();
    _context.uc_link = 0;
    //Alocação da memória para a stack
    _context.uc_stack.ss_sp=malloc(STACK_SIZE);
    _context.uc_stack.ss_size=STACK_SIZE;
    //Flags da stack (?)
    _context.uc_stack.ss_flags=0;
    // Criação e alocação do novo contexto
    makecontext(&_context, func, 0);
}


__END_API

#endif

