#ifndef CLIENTENOENCONTRADO_H
#define CLIENTENOENCONTRADO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class ClienteNoEncontrado : public ExcepcionCentroDeportivo {
public:
    ClienteNoEncontrado(string id);
};

#endif
