#ifndef ITERADORCLIENTES_H
#define ITERADORCLIENTES_H

#include <iostream>
using namespace std;

#include "Cliente/NodoCliente.h"

class IteradorClientes {
private:
    NodoCliente *Actual;

public:
    IteradorClientes(NodoCliente *primero);

    bool hayMas();
    Cliente* siguiente();
};

#endif
