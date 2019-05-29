#include "Almacen.h"
#include "ValorOz.h"
#include "Variable.h"
#include "Integer.h"
#include "Doble.h"
#include "Register.h"
#include "variableNoLigada.h"

Almacen::Almacen(){
    this->variables = list<Variable*>();
}

Almacen::Almacen(list<Variable*> variables){
    this->variables = variables;
}

string Almacen::imprimirAlmacen(){
    string cadena = "-------------------------------------\n";
    list<Variable*>:: iterator it;

    for(it = variables.begin(); it != variables.end(); it++){
        cadena += (*it)->obtenerNombre() + " = ";
        cadena += (*it)->obtenerCadenaValor() + "\n";
    }

    cadena += "-------------------------------------\n";

    return cadena;
}

Variable* Almacen::consultarVariable(string nombre){
    list<Variable*>:: iterator it;
    for(it = variables.begin(); it != variables.end(); it++)
        if((*it)->obtenerNombre() == nombre)
            return *it;
    return NULL;
}

bool Almacen::consultarLigadura(string nombre){
    Variable* variable = consultarVariable(nombre);
    if(variable != NULL){
        return variable->obtenerCadenaValor() != "_";
    }
    return false;
}

void Almacen::modificarVariable(string nombre, ValorOz* oz){
    Variable* variable = consultarVariable(nombre);
    variable->modificarValor(oz);
}

void Almacen::agregarVariable(string nombre){

    VariableNoLigada* ptr = new VariableNoLigada;
    Variable* ptr2 = new Variable;

    ptr2->modificarNombre(nombre);
    ptr2->modificarValor(ptr);

    this->variables.push_back(ptr2);
}

list<Variable*> Almacen::obtenerListaVariables(){
    return this->variables;
}

/* TODO: 2019-05-12 Metodo de unificacion comenzarlo por lo menos */
bool Almacen::unificarVariables(ValorOz* valor1, ValorOz* valor2){

    if(valor1->tipo() == valor2->tipo()){
        if(valor1 == valor2) return true;
        else return false;
    }else{
        if((valor1->tipo() == VARIABLE && valor2->tipo() == NO_LIGADO) ||
          (valor2->tipo() == VARIABLE && valor1->tipo() == NO_LIGADO)) return true;

        if(valor1->tipo() == VARIABLE && 
                (((Variable*)valor1)->obtenerValor())->tipo() == NO_LIGADO &&
                valor2->tipo() != NO_LIGADO && valor2->tipo() != VARIABLE){

            Variable* consulta = consultarVariable(((Variable*)valor1)->obtenerNombre());

            if(consulta != NULL){
                modificarVariable(consulta->obtenerNombre(), valor2);
                return true;
            }
            else
                return false;
        }

        if(valor2->tipo() == VARIABLE && 
                (((Variable*)valor2)->obtenerValor())->tipo() == NO_LIGADO &&
                valor1->tipo() != NO_LIGADO && valor1->tipo() != VARIABLE){

            Variable* consulta = consultarVariable(((Variable*)valor2)->obtenerNombre());

            if(consulta != NULL){
                modificarVariable(consulta->obtenerNombre(), valor1);
                return true;
            }
            else
                return false;
        }
    }



}

