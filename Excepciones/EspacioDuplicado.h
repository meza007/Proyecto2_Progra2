#ifndef ESPACIODUPLICADO_H
#define ESPACIODUPLICADO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza al registrar un espacio con un codigo repetido.
class EspacioDuplicado : public ExcepcionCentroDeportivo {
public:
    EspacioDuplicado(string codigo);
};

#endif
