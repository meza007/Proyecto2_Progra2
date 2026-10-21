#ifndef DATOINVALIDO_H
#define DATOINVALIDO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza cuando un dato ingresado o leido no cumple el formato o las reglas.
class DatoInvalido : public ExcepcionCentroDeportivo {
public:
    DatoInvalido(string mensaje);
};

#endif
