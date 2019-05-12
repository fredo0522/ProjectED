#include <ValorOz.h>

#ifndef __VARIABLE_H
#define __VARIABLE_H

class Variable: public ValorOz{
    private:
        ValorOz* valor;
        string nombre;
    public:
        /* Constructor */
        Variable(string, ValorOz);

        /* Metodos de consulta */
        ValorOz* obtenerValor();
        string obtenerCadenaValor();
        string obtenerNombre();
        char tipo();

        /* Metodos modificadores */
        void modificarValor(ValorOz);
        void modificarNomber(string);
};

#endif
