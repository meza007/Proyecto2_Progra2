#ifndef ESPACIONOENCONTRADO_H
#define ESPACIONOENCONTRADO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza cuando se busca un espacio que no esta registrado.
class EspacioNoEncontrado : public ExcepcionCentroDeportivo {
public:
    EspacioNoEncontrado(string codigo);
};

#endif
