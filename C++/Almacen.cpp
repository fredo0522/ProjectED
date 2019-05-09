#include <Almacen.h>

Almacen::Almacen(){
    this->store = NULL;
}

Almacen::Almacen(list<Variable> store){
    this->store = store;
}

string Almacen::imprimirAlmacen(){
    string cadena;
    list<Variable>:: iterator it;

    for(it = store.begin(); it != store.end(); it++)
        cadena += *it->obtenerCadenaValor() + "\n";

    return cadena;
}

ValorOz Almacen::consultarVariable(string name){
    list<Variable>:: iterator it;
    for(it = store.begin(); it != store.end(); it++)
        ValorOz* temp = it->getValue();
        if(temp->getName() == name)
            return temp;
    return NULL;
}

bool Almacen::consultarLigadura(string name){
    ValorOz* variable = consultarVariable(name);
    return variable->getValue() != NULL
}

void  Almacen::modificarVariable(string name, ValorOz oz){
    ValorOz* variable = consultarVariable(name);
    variable->setValue(&oz);
}

void Almacen::agregarVariable(string name){
    Variable variable = Variable(name, NULL);
    this->store.push_back(variable);
}

list<Variable> getListaVariables(){
    return this->store;
}

// TODO: Metodo de unificacion PORFAAA
bool Almacen::unificarVariables(ValorOz valor1, ValorOz valor2){
    bool unificado = false;

}
