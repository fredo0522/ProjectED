#include "ValorOz.h"

#ifndef __INTEGER_H
#define __INTEGER_H

class Integer: public ValorOz{
    private:
        int valor;
    public:
        /* Constructor */
        Integer(int);

        /* Metodos de Consulta */
        string obtenerCadenaValor();
        int obtenerValor();
        char tipo();

        /* Modificadores */
        void modificarValor(int);
};

#endif
