#include <Almacen.h>

Almacen::Almacen(){
    this->store = NULL;
}

Almacen::Almacen(list<ValorOz> store){
    this->store = store;
}

// TODO: Imprimir almacen porfa

ValorOz Almacen::consultarVariable(string name){
    list<ValorOz>:: iterator it;
    for(it = store.begin(); it != store.end(); it++){
        if(it*->getName() == name)
            return it*;
    }
    return NULL;
}

bool Almacen::consultarLigadura(string name){
    ValorOz* variable = consultarVariable(name);
    return variable->getValue() != NULL
}

void  Almacen::modificarVariable(string name, ValorOz oz){
    ValorOz* variable = consultarVariable(name);
    variable->setValue(oz);
}

void Almacen::agregarVariable(string name){
    Variable* variable = new Variable(name, NULL);
    this->store.push_back(variable);
}

list<Variable> getListaVariables(){
    return this->store;
}

// TODO: Metodo de unificacion  PORFAAA
