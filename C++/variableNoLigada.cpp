#include "variableNoLigada.h"

VariableNoLigada::VariableNoLigada(){
    this->tipoDato = NO_LIGADO;
    this->valor = "_";
}

string VariableNoLigada::obtenerCadenaValor(){
    return this->valor;
}

char VariableNoLigada::tipo(){
    return this->tipoDato;
}

string VariableNoLigada::obtenerValor(){
    return this->valor;
}

