#include <ValorOz.h>
#include <Register.h>
#include <Variable.h>
#include <Integer.h>
#include <Double.h>

#ifndef __ALMACEN_H
#define __ALMACEN_H

class Almacen{
    private:
        list<Variable> variables;
    public:
        /* Constructores */
        Almacen();
        Almacen(list<Variable>);

        /* Metodos de consulta */
        string imprimirAlmacen();
        ValorOz* consultarVariable(string);
        bool consultarLigadura(string);
        list<Variable> obtenerListaVariables();

        /* Metodos modificadores */
        void modificarVariable(string, ValorOz);
        void agregarVariable(string);
        bool unificarVariables(ValorOz, ValorOz);
};

#endif
