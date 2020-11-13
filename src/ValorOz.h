#include <string>

#ifndef __VALOROZ_H
#define __VALOROZ_H

/* Constantes para tipos de valores Oz */
#define ENTERO 'I'
#define DECIMAL 'D'
#define REGISTRO 'R'
#define VARIABLE 'V'
#define NO_LIGADO 'N'

using namespace std;

class ValorOz {
    protected:
        char tipoDato;
    public:
        /* Metodos virtuales */
        virtual string obtenerCadenaValor() = 0;
        virtual char tipo() = 0;
};

#endif