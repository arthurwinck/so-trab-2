#ifndef thread_h
#define thread_h

#include "cpu.h"
#include "traits.h"
#include "debug.h"

__BEGIN_API

class Thread
{
protected:
    typedef CPU::Context Context;

public:
    /*
     * Cria uma Thread passando um ponteiro para a função a ser executada
     * e os parâmetros passados para a função, que podem variar.
     * Cria o contexto da Thread.
     * PS: devido ao template, este método deve ser implementado neste mesmo arquivo .h
     */ 
    template<typename ... Tn>
    Thread(void (* entry)(Tn ...), Tn ... an);

    /*
     * Retorna a Thread que está em execução.
     */ 
    static Thread * running() { return _running; }

    /*
     * Método para trocar o contexto entre duas thread, a anterior (prev)
     * e a próxima (next).
     * Deve encapsular a chamada para a troca de contexto realizada pela class CPU.
     * Valor de retorno é negativo se houve erro, ou zero.
     */ 
    static int switch_context(Thread * prev, Thread * next) {
        if (prev && next) {
            //db<Thread>(TRC) << "Trocando contexto Thread::switch_context()"
            // switch_context de CPU é void, ou seja, não sabemos se ele conseguiu executar normalmente
            // Talvez mudar switch_context de CPU para int?
            
            //UPDATE: ORDEM ERRADA, primeiro se troca o _running depois executa switch_context
            // Se for feito do jeito inverso, quando chega em switch_context o código n executa mais 
            Thread::_running = next;
            CPU::switch_context(prev->_context, next->_context);
            return 0;
        } else {
            return -1;
        }
    }

    /*
     * Termina a thread.
     * exit_code é o código de término devolvido pela tarefa (ignorar agora, vai ser usado mais tarde).
     * Quando a thread encerra, o controle deve retornar à main. 
     */  
    void thread_exit (int exit_code);

    /*
     * Retorna o ID da thread.
     */ 
    int id();

    /*
    * Qualquer outro método que você achar necessário para a solução.
    */

    /*
    * Devolve um novo id para uma thread
    */
    static int give_id() {
        
        return Thread::uid;
    }

    /*
    *  Retorna o contexto de uma thread
    */
    Context* context() {return _context;}

private:
    int _id;
    Context * volatile _context;
    static Thread * _running;
    
    /*
    * Atributo que guarda o valor do último id gerado
    * (É incrementado sempre que uma nova thread é cridada)
    */
    static int uid;

    /*
     * Qualquer outro atributo que você achar necessário para a solução.
     */ 

};

//Implementação do Construtor
template<typename ... Tn>
Thread::Thread(void (* entry)(Tn ...), Tn ... an) {
    if (entry) {
        
        //UPDATE: Chamada do debugger
        // db<Thread>(TRC) << "Thread::Thread(): criou thread"
        
        //Criação do Contexto...
        this->_context = new CPU::Context(entry, an...);
        //... Outras inicializações
        // Incremento o valor de id para gerar um novo id para a threadd
        Thread::uid = Thread::uid + 1;
        this->_id = Thread::give_id();
    }
};

__END_API

#endif
