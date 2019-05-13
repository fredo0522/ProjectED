#include "ValorOz.h"

#ifndef __DOUBLE_H
#define __DOUBLE_H

class Double: public ValorOz{
    private:
        double valor;
    public:
        /* Constructor */
        Double(double);

        /* Metodos de Consulta*/
        string obtenerCadenaValor();
        double obtenerValor();
        char tipo();

        /* Modificadores */
        void modificarValor(double);
};

#endif
