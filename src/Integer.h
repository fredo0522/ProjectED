#include "ValorOz.h"
#include <string>

#ifndef __INTEGER_H
#define __INTEGER_H

using namespace std;

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

        /* Sobrecarga de operadores */
        bool operator ==(Integer&);
};

#endif
