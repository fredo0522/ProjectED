#include "ValorOz.h"
#include <set>
#include <string>

#ifndef __VARIABLE_H
#define __VARIABLE_H

using namespace std;

class Variable: public ValorOz{
    private:
        ValorOz* valor;
        string nombre;
        set<ValorOz*> comparison;
    public:
        /* Constructor */
        Variable();
        Variable(string, ValorOz*);

        /* Metodos de consulta */
        ValorOz* obtenerValor();
        string obtenerCadenaValor();
        string obtenerNombre();
        char tipo();

        /* Metodos modificadores */
        void modificarValor(ValorOz*);
        void modificarNombre(string);
};

#endif
