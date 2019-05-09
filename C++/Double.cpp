#include <Double.h>

Double::Double(string name, double value){
	this-> name = name;
	this-> value = value;
}

string Double::obtenerCadenaValor(){
	string stringValue = to_string(this->value);
	return stringValue;
}

double Double::getValue(){
	return this->value;
}

void Double::setValue(double value){
	this->value = value;
}

string Double::getName(){
	return this->name;
}

void Double::setName(string name){
	this-> name = name;
}
