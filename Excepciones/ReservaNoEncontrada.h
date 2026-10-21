#ifndef RESERVANOENCONTRADA_H
#define RESERVANOENCONTRADA_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza cuando se busca una reserva que no existe.
class ReservaNoEncontrada : public ExcepcionCentroDeportivo {
public:
    ReservaNoEncontrada(string codigo);
};

#endif
