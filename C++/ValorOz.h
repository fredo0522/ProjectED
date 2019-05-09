#include <string>

#ifndef __VALOROZ_H
#define __VALOROZ_H

using namespace std;

class ValorOz{
    protected:
        string name;
    public:
        ValorOz(string);
        virtual string obtenerCadenaValor();
        virtual string getName();
        virtual void setName(string);
};


#endif
