#include <ValorOz.h>
#include <list>
#include <iterator>

#ifndef __REGISTER_H
#define __REGISTER_H

class Register: public ValorOz{
    private:
        string etiqueta;
        list<ValorOz> field;
        list<string> fieldNames;
    public:
        Register(string, list<ValorOz>, list<string>);
        string obtenerCadenaValor();
        string obtenerEtiqueta();
        list<string> obtenerCampos();
        char type();
};

#endif

