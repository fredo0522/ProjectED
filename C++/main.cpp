#include "ValorOz.h"
#include "Double.h"
#include "Integer.h"
#include "Register.h"
#include "Variable.h"
#include "Almacen.h"
#include <iostream>
#include <list>
#include <iterator>

/* TODO: 2019-05-12 Not working(error: Undefined reference to Class::Class) */
int main(){
    list<Variable> lista;

    Integer valor(10);
    Variable robert("Alejandro", valor);
    lista.push_back(robert);

    Almacen almacen = Almacen(lista);
    cout << almacen.imprimirAlmacen() << endl;
    return 0;
}

