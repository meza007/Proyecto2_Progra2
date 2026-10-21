#ifndef NODOCLIENTE_H
#define NODOCLIENTE_H
#include "Cliente/Cliente.h"
#include <iostream>
using namespace std;

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
