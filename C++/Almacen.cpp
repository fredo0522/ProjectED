#include "Almacen.h"
#include "ValorOz.h"
#include "Variable.h"
#include "Integer.h"
#include "Doble.h"
#include "Register.h"
#include "variableNoLigada.h"

Almacen::Almacen(){
    this->variables = list<Variable*>();
}

Almacen::Almacen(list<Variable*> variables){
    this->variables = variables;
}

string Almacen::imprimirAlmacen(){
    string cadena = "";
    list<Variable*>:: iterator it;

    for(it = variables.begin(); it != variables.end(); it++){
        cadena += (*it)->obtenerNombre() + " = ";
        cadena += (*it)->obtenerCadenaValor() + "\n";
    }

    return cadena;
}

Variable* Almacen::consultarVariable(string nombre){
    list<Variable*>:: iterator it;
    for(it = variables.begin(); it != variables.end(); it++)
        if((*it)->obtenerNombre() == nombre)
            return *it;
    return NULL;
}

bool Almacen::consultarLigadura(string nombre){
    Variable* variable = consultarVariable(nombre);
    if(variable != NULL){
        return variable->obtenerCadenaValor() != "_";
    }
    return false;
}

void Almacen::modificarVariable(string nombre, ValorOz* oz){
    Variable* variable = consultarVariable(nombre);
    variable->modificarValor(oz);
}

void Almacen::agregarVariable(string nombre){

    VariableNoLigada* ptr = new VariableNoLigada;
    Variable* ptr2 = new Variable;

    ptr2->modificarNombre(nombre);
    ptr2->modificarValor(ptr);

    this->variables.push_back(ptr2);
}

list<Variable*> Almacen::obtenerListaVariables(){
    return this->variables;
}

/* TODO: 2019-05-12 Metodo de unificacion comenzarlo por lo menos */
bool Almacen::unificarVariables(ValorOz* valor1, ValorOz* valor2){
    bool unificado = false;

}
