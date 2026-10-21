#ifndef CLIENTEDUPLICADO_H
#define CLIENTEDUPLICADO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class ClienteDuplicado : public ExcepcionCentroDeportivo {
public:
    ClienteDuplicado(string id);
};

#endif
