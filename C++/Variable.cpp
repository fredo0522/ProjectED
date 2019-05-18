#include "Variable.h"

Variable::Variable(string name, ValorOz valor){
this->name = name;
ValorOz* newValue = &valor;
this->valor = newValue;
this->tipo = VARIABLE;
}

ValorOz Variable::getValue(){
    return this->valor;
}

void Variable::modificarValor(ValorOz valor){
    this->valor = valor;
}

string Variable::obtenerCadenaValor(){
    return valor->obtenerCadenaValor();
}

string Variable::obtenerNombre(){
    return this->nombre;
}

void Variable::modificarNombre(string nombre){
    this->nombre = nombre;
}

char Variable::tipo(){
    return this->tipo;
}
