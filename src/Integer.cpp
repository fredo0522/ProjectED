#include "Integer.h"

Integer::Integer(int valor){
    this->valor = valor;
    this->tipoDato = ENTERO;
}

string Integer::obtenerCadenaValor(){
    return to_string(this->valor);
}

int Integer::obtenerValor(){
    return this->valor;
}

void Integer::modificarValor(int valor){
    this->valor = valor;
}

char Integer::tipo(){
    return tipoDato;
}

bool Integer::operator ==(Integer& i){
    return this->obtenerValor() == i.obtenerValor();
}
