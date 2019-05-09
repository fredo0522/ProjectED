#include <Double.h>

Double::Double(double value){
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

char Double::type(){
    return DOUBLE;
}
