#include <string>

#ifndef __VALOROZ_H
#define __VALOROZ_H

/* Constantes para tipos de valores Oz */
#define ENTERO 'I'
#define DECIMAL 'D'
#define REGISTRO 'R'
#define VARIABLE 'V'

using namespace std;

class ValorOz{
    public:
    	ValorOz();
        /* Metodos virtuales */
        virtual string obtenerCadenaValor();
        virtual char tipo();
};

#endif
