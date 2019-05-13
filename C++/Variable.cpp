#include "Variable.h"

Variable::Variable(string name, ValorOz valor){
    this->name = name;
    ValorOz* newValue = &valor;
    this->valor = newValue;
}

ValorOz* Variable::getValue(){
    return this->valor;
}

void Variable::modificarValor(ValorOz valor){
    ValorOz* nuevoValor = &valor;
    this->valor = nuevoValor;
}

string Variable::obtenerCadenaValor(){
    if(this->valor == NULL) return "_";
    return valor->obtenerCadenaValor();
}

string Variable::obtenerNombre(){
    return this->nombre;
}

void Variable::modificarNombre(string nombre){
    this->nombre = nombre;
}

char Variable::tipo(){
    return VARIABLE;
}
