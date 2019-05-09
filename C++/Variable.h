#include <ValorOz.h>

#ifndef __VARIABLE_H
#define __VARIABLE_H

class Variable: public ValorOz{
    private:
        ValorOz* value;
        string name;
    public:
        Variable(string, ValorOz);
        ValorOz* getValue();
        void setValue(ValorOz);
        string obtenerCadenaValor();
        string getName();
        void setName(string);
        char type();
};

#endif
