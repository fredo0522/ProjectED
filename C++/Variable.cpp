#include <Variable.h>

Variable::Variable(string name, ValorOz value){
    this->name = name;
    ValorOz* newValue = &value;
    this->value = newValue;
}

ValorOz* Variable::getValue(){
    return this->value;
}

void Variable::setValue(ValorOz value){
    ValorOz* newValue = &value;
    this->value = newValue;
}

string Variable::obtenerCadenaValor(){
    return value->obtenerCadenaValor();
}

string Variable::getName(){
    return this->name;
}

void Variable::setName(string name){
    this->name = name;
}

char Variable::type(){
    return VARIABLE;
}
