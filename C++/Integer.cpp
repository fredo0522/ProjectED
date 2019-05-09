#include <Integer.h>

Intger::Integer(string name, int value){
    this->name = name;
    this->value = value;
}

string Integer::obtenerCadenaValor(){
    string stringValue = to_string(this->value);
    return stringValue;
}

int Integer::getValue(){
    return this->value;
}

void Integer::setValue(int value){
    this->value = value;
}

string Integer::getName(){
    return this->name;
}

void Integer::setName(int value){
    this->value = value;
}
