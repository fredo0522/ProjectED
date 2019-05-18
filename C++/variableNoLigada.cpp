#include "variableNoLigada.h"

VariableNoLigada::VariableNoLigada(){
    this->tipo = NO_LIGADO;
    this->valor = "_";
}

string VariableNoLigada::obtenerCadenaValor(){
    return this->valor;
}

char VariableNoLigada::tipo(){
    return this->tipo;
}

