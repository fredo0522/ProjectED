#include <ValorOz.h>
#include <Register.h>
#include <Variable.h>
#include <Integer.h>
#include <Double.h>

#ifndef __ALMACEN_H
#define __ALMACEN_H

class Almacen{
    private:
        list<Variable> store;
    public:
        Almacen();
        Almacen(list<Variable>);
        string imprimirAlmacen();
        ValorOz* consultarVariable(string);
        bool consultarLigadura(string);
        void modificarVariable(string, ValorOz);
        void agregarVariable(string);
        list<Variable> getListaVariables();
        bool unificarVariables(ValorOz, ValorOz);
};

#endif
