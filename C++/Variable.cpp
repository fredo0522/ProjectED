#include <Variable.h>

Variable::Variable(string name, ValorOz value){
    this->name = name;
    this->value = value;
}

ValorOz Variable::getValue(){
    return this->value;
}

void Variable::setValue(ValorOz value){
    this->value = value;
}

string Variable::obtenerCadenaValor(){
    return value*->obtenerCadenaValor();
}

string Variable::getName(){
    return this->name;
}

void Variable::setName(string name){
    this->name = name;
}
