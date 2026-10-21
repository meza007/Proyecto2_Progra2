#ifndef CLIENTENOENCONTRADO_H
#define CLIENTENOENCONTRADO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza cuando se busca un cliente que no esta registrado.
class ClienteNoEncontrado : public ExcepcionCentroDeportivo {
public:
    ClienteNoEncontrado(string id);
};

#endif
