#ifndef RESERVANOENCONTRADA_H
#define RESERVANOENCONTRADA_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class ReservaNoEncontrada : public ExcepcionCentroDeportivo {
public:
    ReservaNoEncontrada(string codigo);
};

#endif
