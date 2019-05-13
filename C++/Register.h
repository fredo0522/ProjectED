#include "ValorOz.h"
#include <list>
#include <iterator>

#ifndef __REGISTER_H
#define __REGISTER_H

class Register: public ValorOz{
    private:
        string etiqueta;
        list<ValorOz> campos;
        list<string> nombreCampos;
    public:
        /* Constructor */
        Register(string, list<ValorOz>, list<string>);

        /* Metodos de consulta */
        string obtenerCadenaValor();
        string obtenerEtiqueta();
        list<string> obtenerCampos();
        char tipo();
};

#endif

