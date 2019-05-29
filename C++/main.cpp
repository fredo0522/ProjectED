#include "ValorOz.h"
#include "Doble.h"
#include "Register.h"
#include "Variable.h"
#include "Integer.h"
#include "Almacen.h"
#include "variableNoLigada.h"
#include <string>
#include <iostream>
#include <list>
#include <iterator>
#include <iostream>
#include <cstring>

using namespace std;

ValorOz* convertirValor(string valorCadena, Almacen almacen){

    if(valorCadena[0] <= 57 && valorCadena[0] >= 48){
        bool isDouble = false;

        for(int i = 0; i < valorCadena.size(); i++){
            if(valorCadena[i] == '.'){
                isDouble = true;
                break;
            } 
        }

        if(isDouble)
            return new Doble(stod(valorCadena));
        else
            return new Integer(stoi(valorCadena));

    }else{
        if(valorCadena[0] == '_') return new VariableNoLigada;

        bool isRegister = false;
        for(int i = 0; i < valorCadena.size(); i++){
            if(valorCadena[i] == '('){
                isRegister = true;
                break;
            }
        }

        if(!isRegister){
            Variable* alter = almacen.consultarVariable(valorCadena);
            string nombre = alter->obtenerNombre();
            ValorOz* valorAsig = alter->obtenerValor();
            return new Variable(nombre, valorAsig);
        }else{
            string etiqueta = valorCadena.substr(0, valorCadena.find("(")), temp = "";
            list<string> nombreCampos;
            list<ValorOz*> campos;

            for(int i = valorCadena.find("(") + 1; i < valorCadena.size(); i++){
                if(valorCadena[i] == '('){
                    int j;
                    bool end = false;
                    for(j = i; j < valorCadena.size() && !end; j++){
                        temp += valorCadena[j];
                        if(valorCadena[j] == ')') end = true;
                    }
                    i = j;
                    campos.push_back(convertirValor(temp, almacen));
                    temp = "";
                }else if(valorCadena[i] == ':'){
                    nombreCampos.push_back(temp);
                    temp = "";
                }else if(valorCadena[i] == ' '){
                    campos.push_back(convertirValor(temp, almacen));
                    temp = "";
                }else{
                    temp += valorCadena[i];
                }
            }
            return new Register(etiqueta, campos, nombreCampos);
        }
    }
}

int main(){
    string unification;
    Almacen almacen;
    almacen.agregarVariable("v");
    almacen.agregarVariable("t");
    almacen.agregarVariable("z");
    almacen.agregarVariable("y");
    almacen.agregarVariable("w");

    while(getline(cin, unification)){
        string valorCadena1 = unification.substr(0, unification.find("="));
        string valorCadena2 = unification.substr(unification.find("=") + 1,
                unification.size() - 1);


        ValorOz* valor1 = convertirValor(valorCadena1, almacen);
        ValorOz* valor2 = convertirValor(valorCadena2, almacen);

        /* if(valor1->tipo() == ENTERO) */
        /*     cout << ((Integer*)valor1)->obtenerCadenaValor() << endl; */
        /* else if(valor1->tipo() == DECIMAL) */
        /*     cout << ((Doble*)valor1)->obtenerCadenaValor() << endl; */
        /* else if(valor1->tipo() == REGISTRO) */
        /*     cout << ((Register*)valor1)->obtenerCadenaValor() << endl; */
        /* else if(valor1->tipo() == VARIABLE) */
        /*     cout << ((Variable*)valor1)->obtenerCadenaValor() << endl; */
        /* else */
        /*     cout << ((VariableNoLigada*)valor1)->obtenerCadenaValor() << endl; */

        bool confirmacion = almacen.unificarVariables(valor1, valor2);

        if(confirmacion){
            cout << "Se hizo exitosamente la unificacion" << endl;
        }else{
            cout << "No se pudo hacer la unificacion" << endl;
        }
    }

    cout << almacen.imprimirAlmacen() << endl;

    return 0;
}

