#include <ValorOz.h>

#ifndef __INTEGER_H
#define __INTEGER_H

class Integer: public ValorOz{
    private:
        int value;
    public:
        Integer(int);
        string obtenerCadenaValor();
        int getValue();
        void setValue(int);
        char type();
};

#endif
