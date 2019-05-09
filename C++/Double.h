#include <ValorOz.h>

#ifndef __DOUBLE_H
#define __DOUBLE_H

class Double: public ValorOz{
    private:
        double value;
    public:
        Double(double);
        string obtenerCadenaValor();
        double getValue();
        void setValue(double);
        char type();
};

#endif
