#include "ValorOz.h"
#include "Integer.h"
#include "Doble.h"
#include "Register.h"
#include "Variable.h"
#include "variableNoLigada.h"
#include <string>
#include <list>
#include <iterator>

#ifndef __ALMACEN_H
#define __ALMACEN_H

using namespace std;

class Almacen{
    private:
        list<Variable*> variables;
    public:
        /* Constructores */
        Almacen();
        Almacen(list<Variable*>);

        /* Metodos de consulta */
        string imprimirAlmacen();
        Variable* consultarVariable(string);
        bool consultarLigadura(string);
        list<Variable*> obtenerListaVariables();

        /* Metodos modificadores */
        void modificarVariable(string, ValorOz*);
        void agregarVariable(string);
        bool unificarVariables(ValorOz*, ValorOz*);
};

#endif
