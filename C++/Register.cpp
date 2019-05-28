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

list<string> Register::obtenerNombreCampos(){
    return this->nombreCampos;
}

char Register::tipo(){
    return this->tipoDato;
}

bool Register::operator ==(Register& r){
    if(obtenerEtiqueta() == r.obtenerEtiqueta()){
        if(obtenerNombreCampos().size() == r.obtenerNombreCampos().size()){
            list<string>:: iterator it1, it2;
            for(it1 = obtenerNombreCampos().begin(); it1 != obtenerNombreCampos().end();
                    it1++){
                bool exist = false;
                for(it2 = r.obtenerNombreCampos().begin(); 
                        it2 != r.obtenerNombreCampos().end() && !exist; it2++){
                    if(*it1 == *it2) exist = true;
                }

                if(!exist) return false;
            }

        }else{
            return false;
        }

        if(obtenerCampos().size() == r.obtenerCampos().size()){
            list<ValorOz*>:: iterator it1, it2;
            for(it1 = obtenerCampos().begin(); it1 != obtenerCampos().end(); it1++){
                bool exist = false;
                for(it2 = r.obtenerCampos().begin(); 
                        it2 != r.obtenerCampos().end() && !exist; it2++){

                    if((*it1)->tipo() == (*it2)->tipo()){
                        if((*it1)->tipo() == ENTERO){
                            Integer* number1 = (Integer*) *it1;
                            Integer* number2 = (Integer*) *it2;
                            if(number1 == number2) exist = true;
                        }else if((*it1)->tipo() == DECIMAL){
                            Doble* double1 = (Doble*) *it1;
                            Doble* double2 = (Doble*) *it2;
                            if(double1 == double2) exist = true;
                        }else if((*it1)->tipo() == REGISTRO){
                            Register* register1 = (Register*) *it1;
                            Register* register2 = (Register*) *it2;
                            if(register1 == register2) exist = true;
                        }else if((*it1)->tipo() == VARIABLE){
                            Variable* variable1 = (Variable*) *it1;
                            Variable* variable2 = (Variable*) *it2;
                            if(variable1 == variable2) exist = true;
                        }else if((*it1)->tipo() == NO_LIGADO){
                            exist = true;
                        }
                    }
                }

                if(!exist) return false;
            }

        }else{
            return false;
        }

        return true;
    }
    return false;
}
