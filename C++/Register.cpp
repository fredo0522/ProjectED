#include "Register.h"

Register::Register(string etiqueta, list<ValorOz> campos, list<string> nombreCampos){
    this->etiqueta = etiqueta;
    this->campos = campos;
    this->nombreCampos = nombreCampos;
    this-> tipo = REGISTRO;
}

string Register::obtenerCadenaValor(){
    string cadena = etiqueta + '(';

    list<string>::iterator it1;
    list<ValorOz>::iterator it2;

    for(it1 = nombreCampos.begin(), it2 = campos.begin(); it2 != campos.end();
            it1++,it2++)
        cadena += " " + it1 + ":" + it2->obtenerCadenaValor();

    cadena += ')';
    return cadena;
}

string Register::obtenerEtiqueta(){
    return this->etiqueta;
}

list<string> Register::obtenerCampos(){
    return this->campos;
}

char Register::tipo(){
    return this->tipo;
}
