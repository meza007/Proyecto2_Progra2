#ifndef ITERADORCLIENTES_H
#define ITERADORCLIENTES_H
#include "Cliente/NodoCliente.h"
#include <iostream>
using namespace std;


class IteradorClientes {
private:
    NodoCliente *Actual;

public:
    IteradorClientes(NodoCliente *primero);

    bool hayMas();
    Cliente* siguiente();
};

#endif
