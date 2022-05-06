#include "cpu.h"
#include <iostream>
#include "ucontext.h"

__BEGIN_API

void CPU::Context::save()
{
    //adicionar implementação
    getcontext(&this->_context);
}

void CPU::Context::load()
{
    //adicionar implementação
    setcontext(&this->_context);
}

CPU::Context::~Context()
{
    //adicionar implementação
}

void CPU::switch_context(Context *from, Context *to)
{
     //implementação do método
     swapcontext(&from->_context, &to->_context);
}

__END_API
