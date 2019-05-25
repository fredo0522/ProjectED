#include "Almacen.h"

Almacen::Almacen(){
    this->variables = list<Variable>();
}

Almacen::Almacen(list<Variable> variables){
    this->variables = variables;
}

string Almacen::imprimirAlmacen(){
    string cadena = "";
    list<Variable*>:: iterator it;

    for(it = variables.begin(); it != variables.end(); it++){
        cadena += *it->obtenerNombre() + "-> ";
        cadena += *it->obtenerCadenaValor() + "\n";
    }

    return cadena;
}

Variable* Almacen::consultarVariable(string nombre){
    list<Variable*>:: iterator it;
    for(it = variables.begin(); it != variables.end(); it++)
        if(*it->obtenerNombre() == nombre)
            return *it;
    return NULL;
}

bool Almacen::consultarLigadura(string nombre){
    Variable* variable = consultarVariable(nombre);
    if(variable != NULL){
        return variable->obtenerCadenaValor() != "_"
    }
    return false;
}

void  Almacen::modificarVariable(string nombre, ValorOz oz){
    Variable* variable = consultarVariable(nombre);
    variable->modificarValor(oz);
}

void Almacen::agregarVariable(string nombre){
    Variable* variable = new Variable(nombre, VariableNoLigada());
    this->variables.push_back(&variable);
}

list<Variable> obtenerListaVariables(){
    return this->variables;
}

/* TODO: 2019-05-12 Metodo de unificacion comenzarlo por lo menos */
bool Almacen::unificarVariables(ValorOz valor1, ValorOz valor2){
    bool unificado = false;

}
