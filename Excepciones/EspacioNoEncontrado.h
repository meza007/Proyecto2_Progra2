#ifndef ESPACIONOENCONTRADO_H
#define ESPACIONOENCONTRADO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class EspacioNoEncontrado : public ExcepcionCentroDeportivo {
public:
    EspacioNoEncontrado(string codigo);
};

#endif
