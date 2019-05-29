#include "ValorOz.h"
#include <list>
#include <iterator>
#include <string>

#ifndef __REGISTER_H
#define __REGISTER_H

using namespace std;

class Register: public ValorOz{
    private:
        string etiqueta;
        list<ValorOz*> campos;
        list<string> nombreCampos;
    public:
        /* Constructor */
        Register(string, list<ValorOz*>, list<string>);

        /* Metodos de consulta */
        string obtenerCadenaValor();
        string obtenerEtiqueta();
        list<ValorOz*> obtenerCampos();
        list<string> obtenerNombreCampos();
        char tipo();
        bool camposIguales(Register*);

        /* Sobrecarga de operadores */
        bool operator ==(Register&);
};

#endif

