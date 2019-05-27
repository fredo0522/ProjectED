#include "ValorOz.h"
#include "Variable.h"
#include "Integer.h"
#include "Doble.h"
#include "Register.h"
#include "variableNoLigada.h"

Variable::Variable(){}

Variable::Variable(string name, ValorOz* valor){
    this->nombre = name;
    modificarValor(valor);
    this->tipoDato = VARIABLE;
}

ValorOz* Variable::obtenerValor(){
    return this->valor;
}

void Variable::modificarValor(ValorOz* valor){
    if(valor->tipo() == ENTERO){
        Integer* valorExacto = (Integer*) valor;
        this->valor = valorExacto;
        this->comparison.insert(valorExacto);
    }else if(valor->tipo() == DECIMAL){
        Doble* valorExacto = (Doble*) valor;
        this->valor = valorExacto;
        this->comparison.insert(valorExacto);
    }else if (valor->tipo() == REGISTRO){
        Register* valorExacto = (Register*) valor;
        this->valor = valorExacto;
        list<ValorOz*> campos = valorExacto->obtenerListaCampos();
        list<ValorOz*>:: iterator it;
        for(it = campos.begin(); it != campos.end(); it++){
            comparison.insert(*it);
        }

    }else if (valor->tipo() == VARIABLE){
        Variable* valorExacto = (Variable*) valor;
        this->valor = valorExacto;
        this->comparison.insert(valorExacto);
    }else{
        VariableNoLigada* valorExacto = (VariableNoLigada*) valor;
        this->valor = valorExacto;
        this->comparison.insert(valorExacto);
    }

}

string Variable::obtenerCadenaValor(){
    if(valor->tipo() == ENTERO){
        Integer* valorExacto = (Integer*) valor;
        return valorExacto->obtenerCadenaValor();
    }else if(valor->tipo() == DECIMAL){
        Doble* valorExacto = (Doble*) valor;
        return valorExacto->obtenerCadenaValor();
    }else if (valor->tipo() == REGISTRO){
        Register* valorExacto = (Register*) valor;
        return valorExacto->obtenerCadenaValor();
    }else if (valor->tipo() == VARIABLE){
        Variable* valorExacto = (Variable*) valor;
        return valorExacto->obtenerCadenaValor();
    }else{
        VariableNoLigada* valorExacto = (VariableNoLigada*) valor;
        return valorExacto->obtenerCadenaValor();
    }
}

string Variable::obtenerNombre(){
    return this->nombre;
}

void Variable::modificarNombre(string name){
    this->nombre = name;
}

char Variable::tipo(){
    return this->tipoDato;
}
