#include "Register.h"
#include "ValorOz.h"
#include "Variable.h"
#include "Integer.h"
#include "Doble.h"
#include "variableNoLigada.h"

Register::Register(string etiqueta, list<ValorOz*> campos, list<string> nombreCampos){
    this->etiqueta = etiqueta;
    this->campos = campos;
    this->nombreCampos = nombreCampos;
    this->tipoDato = REGISTRO;
}

string Register::obtenerCadenaValor(){
    string cadena = etiqueta + '(';

    list<string>::iterator it1;
    list<ValorOz*>::iterator it2;

    for(it1 = nombreCampos.begin(), it2 = campos.begin(); it2 != campos.end(); it1++,it2++){
        cadena += " " + *it1 + ":";

        if((*it2)->tipo() == ENTERO){
            Integer* valorExacto = (Integer*) *it2;
            cadena += valorExacto->obtenerCadenaValor();
        }else if((*it2)->tipo() == DECIMAL){
            Doble* valorExacto = (Doble*) *it2;
            cadena += valorExacto->obtenerCadenaValor();
        }else if((*it2)->tipo() == REGISTRO){
            Register* valorExacto = (Register*) *it2;
            cadena += valorExacto->obtenerCadenaValor();
        }else if ((*it2)->tipo() == VARIABLE){
            Variable* valorExacto = (Variable*) *it2;
            cadena += valorExacto->obtenerCadenaValor();
        }else{
            VariableNoLigada* valorExacto = (VariableNoLigada*) *it2;
            cadena += valorExacto->obtenerCadenaValor();
        }

    }

    cadena += " )";
    return cadena;
}

string Register::obtenerEtiqueta(){
    return this->etiqueta;
}

list<ValorOz*> Register::obtenerCampos(){
    return this->campos;
}

char Register::tipo(){
    return this->tipoDato;
}
