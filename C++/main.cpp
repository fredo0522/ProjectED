#include "ValorOz.h"
#include "Doble.h"
#include "Register.h"
#include "Variable.h"
#include "Integer.h"
#include "Almacen.h"
#include "variableNoLigada.h"
#include <iostream>
#include <list>
#include <iterator>
#include <iostream>


using namespace std;

int main(){
    VariableNoLigada reg;
    cout << reg.obtenerCadenaValor() << endl;

    return 0;
}

