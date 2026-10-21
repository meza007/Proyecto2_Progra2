#ifndef ESPACIODUPLICADO_H
#define ESPACIODUPLICADO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class EspacioDuplicado : public ExcepcionCentroDeportivo {
public:
    EspacioDuplicado(string codigo);
};

#endif
