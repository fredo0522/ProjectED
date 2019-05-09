#include <ValorOz.h>

#ifndef __VARIABLE_H
#define __VARIABLE_H

class Variable: public ValorOz{
    private:
        ValorOz* value;
    public:
        Variable(string, ValorOz);
        ValorOz getValue();
        void setValue(ValorOz);
};

#endif
