#include <string>

#ifndef __VALOROZ_H
#define __VALOROZ_H

#define INTEGER 'I'
#define DOUBLE 'D'
#define REGISTER 'R'
#define VARIABLE 'V'

using namespace std;

class ValorOz{
    public:
        virtual string obtenerCadenaValor();
        virtual char type();
};

#endif
