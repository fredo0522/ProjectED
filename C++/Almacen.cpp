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
        if(valor1->tipo() == VARIABLE && valor2->tipo() == VARIABLE){
            if((((Variable*)valor1)->obtenerValor())->tipo() == REGISTRO &&
                    (((Variable*)valor2)->obtenerValor())->tipo() == REGISTRO){

                Register* registro1 = (Register*)((Variable*)valor1)->obtenerValor();
                Register* registro2 = (Register*)((Variable*)valor2)->obtenerValor();

                if(registro1->obtenerEtiqueta() != registro2->obtenerEtiqueta())
                    return false;

                if((registro1->obtenerNombreCampos()).size() !=
                        (registro2->obtenerNombreCampos()).size()) return false;

                if(registro1->camposIguales(registro2)){
                    int contador1 = 0, contador2 = 0;
                    list<string>:: iterator it1 = registro1->obtenerNombreCampos().begin();
                    list<string>:: iterator it2 = registro2->obtenerNombreCampos().begin();
                    for(; it1 != registro1->obtenerNombreCampos().end(); it1++){
                        for(; it2 != registro2->obtenerNombreCampos().end(); it2++){
                            if(*it1 == *it2){

                                list<ValorOz*>:: iterator itValor1 =
                                    registro1->obtenerCampos().begin();
                                list<ValorOz*>:: iterator itValor2 =
                                    registro2->obtenerCampos().begin();

                                while(contador1--){
                                    itValor1++;
                                }

                                while(contador2--){
                                    itValor2++;
                                }

                                bool flag = unificarVariables(*itValor1, *itValor2);
                                if(!flag) return false;
                                
                            }else{
                                contador2++;
                            }
                        }
                        contador1++;
                    }
                    return true;
                }else{
                    return false;
                }

            }else{
                if(valor1 == valor2) return true;
                else return false;
            }
        }else{
            if(valor1 == valor2) return true;
            else return false;
        }
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
            }else{
                return false;
            }
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

        if(valor1->tipo() == VARIABLE &&
                (((Variable*)valor1)->obtenerValor())->tipo() == NO_LIGADO && 
                valor2->tipo() == VARIABLE && 
                (((Variable*)valor2)->obtenerValor())->tipo() != NO_LIGADO){

            Variable* consulta1 = consultarVariable(((Variable*)valor1)->obtenerNombre());
            Variable* consulta2 = consultarVariable(((Variable*)valor2)->obtenerNombre());
            modificarVariable(consulta1->obtenerNombre(), consulta2->obtenerValor());
            return true;
        }

        if(valor2->tipo() == VARIABLE &&
                (((Variable*)valor2)->obtenerValor())->tipo() == NO_LIGADO && 
                valor1->tipo() == VARIABLE && 
                (((Variable*)valor1)->obtenerValor())->tipo() != NO_LIGADO){

            Variable* consulta1 = consultarVariable(((Variable*)valor1)->obtenerNombre());
            Variable* consulta2 = consultarVariable(((Variable*)valor2)->obtenerNombre());
            modificarVariable(consulta2->obtenerNombre(), consulta1->obtenerValor());
            return true;
        }

        if(valor1->tipo() == VARIABLE &&
                (((Variable*)valor1)->obtenerValor())->tipo() != NO_LIGADO &&
                valor2->tipo() != NO_LIGADO && valor2->tipo() != VARIABLE){

            if((((Variable*)valor1)->obtenerValor())->tipo() == valor2->tipo()){
                if(valor2->tipo() == ENTERO){
                    Integer* valorComparison = 
                        (Integer*)((Variable*)valor1)->obtenerValor();
                    if(((Integer*)valor2) == valorComparison) return true;
                    else return false;
                }else if(valor2->tipo() == DECIMAL){
                    Doble* valorComparison = (Doble*)((Variable*)valor1)->obtenerValor();
                    if(((Doble*)valor2) == valorComparison) return true;
                    else return false;
                }else if(valor2->tipo() == REGISTRO){
                    Register* valorComparison = 
                        (Register*)((Variable*)valor1)->obtenerValor();
                    if(((Register*)valor2) == valorComparison) return true;
                    else return false;
                }
            }
        }

        if(valor2->tipo() == VARIABLE &&
                (((Variable*)valor2)->obtenerValor())->tipo() != NO_LIGADO &&
                valor1->tipo() != NO_LIGADO && valor1->tipo() != VARIABLE){

            if((((Variable*)valor2)->obtenerValor())->tipo() == valor1->tipo()){
                if(valor1->tipo() == ENTERO){
                    Integer* valorComparison =
                        (Integer*)((Variable*)valor2)->obtenerValor();
                    if(((Integer*)valor1) == valorComparison) return true;
                    else return false;
                }else if(valor1->tipo() == DECIMAL){
                    Doble* valorComparison = (Doble*)((Variable*)valor2)->obtenerValor();
                    if(((Doble*)valor1) == valorComparison) return true;
                    else return false;
                }else if(valor1->tipo() == REGISTRO){
                    Register* valorComparison = 
                        (Register*)((Variable*)valor2)->obtenerValor();
                    if(((Register*)valor1) == valorComparison) return true;
                    else return false;
                }
            }
        }
    }
}

