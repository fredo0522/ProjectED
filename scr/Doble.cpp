#include "Doble.h"

Doble::Doble(double value){
	this->valor = value;
    this->tipoDato = DECIMAL;
}

string Doble::obtenerCadenaValor(){
	return to_string(this->valor);
}

double Doble::obtenerValor(){
	return this->valor;
}

void Doble::modificarValor(double valor){
	this->valor = valor;
}

char Doble::tipo(){
    return tipoDato;
}

bool Doble::operator ==(Doble& d){
    return obtenerValor() == d.obtenerValor();
}
