#include "ValorOz.h"
#include "Doble.h"
#include "Register.h"
#include "Variable.h"
#include "Integer.h"
#include "Almacen.h"
#include <iostream>
#include <list>
#include <iterator>
#include <iostream>


using namespace std;

/* TODO: 2019-05-18 Hacer clase Variable no ligada, acomodar todas las includes
 * y ValorOz agregar char tipo como atributo, adicionalmente -> poner todo lo que viene
 * con eso en las demas clases, poner todo en punteros */

/* TODO: 2019-05-12 Not working(error: Undefined reference to Class::Class) */
int main(){
    list<Variable*> lista;

    Integer valor = Integer(10);
    Doble valorDouble = Doble(2.0);

    cout << valor.obtenerCadenaValor() << endl;
    cout << valorDouble.obtenerCadenaValor() << endl;
    return 0;
}

