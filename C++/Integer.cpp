#include <Integer.h>

Integer::Integer(int value){
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

char Integer::type(){
    return INTEGER;
}
