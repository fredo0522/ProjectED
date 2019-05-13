#include "Double.h"

Double::Double(double value){
	this-> value = value;
}

string Double::obtenerCadenaValor(){
	return to_string(this->valor);
}

double Double::obtenerValor(){
	return this->valor;
}

void Double::modificarValor(double valor){
	this->valor = valor;
}

char Double::tipo(){
    return DECIMAL;
}
