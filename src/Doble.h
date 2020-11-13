#include "ValorOz.h"
#include <string>

#ifndef __DOBLE_H
#define __DOBLE_H

using namespace std;

class Doble: public ValorOz{
    private:
        double valor;
    public:
        /* Constructor */
        Doble(double);

        /* Metodos de Consulta */
        string obtenerCadenaValor();
        double obtenerValor();
        char tipo();

        /* Modificadores */
        void modificarValor(double);

        /* Sobrecarga de operadores */
        bool operator ==(Doble&);
};

#endif
