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
    auto v1, v2;

    if(valor1->tipo() == ENTERO) v1 = (Integer*) valor1;
    else if(valor1->tipo() == DECIMAL) v1 = (Doble*) valor1;
    else if(valor1->tipo() == REGISTRO) v1 = (Register*) valor1;
    else if(valor1->tipo() == VARIABLE) v1 = (Variable*) valor1;
    else v1 = (VariableNoLigada*) valor1;

    if(valor2->tipo() == ENTERO) v2 = (Integer*) valor2;
    else if(valor2->tipo() == DECIMAL) v2 = (Doble*) valor2;
    else if(valor2->tipo() == REGISTRO) v2 = (Register*) valor2;
    else if(valor2->tipo() == VARIABLE) v2 = (Variable*) valor2;
    else v2 = (VariableNoLigada*) valor2;

    if(v1->tipo() == v2->tipo()){
        if(v1 == v2) return true;
        else return false;
    }else{

    }



}

