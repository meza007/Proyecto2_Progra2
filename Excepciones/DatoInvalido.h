#ifndef DATOINVALIDO_H
#define DATOINVALIDO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class DatoInvalido : public ExcepcionCentroDeportivo {
public:
    DatoInvalido(string mensaje);
};

#endif
