#include <ValorOz.h>

#ifndef __VARIABLE_H
#define __VARIABLE_H

class Variable: public ValorOz{
    private:
        ValorOz* valor;
        string nombre;
    public:
        Variable(string, ValorOz);
        ValorOz* obtenerValor();
        void modificarValor(ValorOz);
        string obtenerCadenaValor();
        string obtenerNombre();
        void modificarNomber(string);
        char tipo();
};

#endif
