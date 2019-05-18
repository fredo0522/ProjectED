#include "Integer.h"

Integer::Integer(int valor){
    this->valor = valor;
    this->tipo = ENTERO;
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
    return ENTERO;
}
