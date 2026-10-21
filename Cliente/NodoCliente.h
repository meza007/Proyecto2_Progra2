#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H

#include <iostream>
using namespace std;

#include "Cliente/Cliente.h"


class NodoCliente {
private:
    Cliente *Clie;
    NodoCliente *Sig;

public:
    NodoCliente();
    NodoCliente(Cliente *clie, NodoCliente *sig);

    Cliente* getCliente();
    void setCliente(Cliente *clie);

    NodoCliente* getSiguiente();
    void setSiguiente(NodoCliente *sig);
};

#endif
