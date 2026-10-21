#ifndef CLIENTEDUPLICADO_H
#define CLIENTEDUPLICADO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza al registrar un cliente con una identificacion repetida.
class ClienteDuplicado : public ExcepcionCentroDeportivo {
public:
    ClienteDuplicado(string id);
};

#endif
