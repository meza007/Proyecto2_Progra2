#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include "Cliente/NodoCliente.h"
#include "Cliente/IteradorClientes.h"
#include <iostream>
using namespace std;

class ListaClientes {
private:
    NodoCliente *Primero;
    int Cantidad;

public:
    ListaClientes();
    ~ListaClientes();

    void IngresaCliente(Cliente *clie);
    Cliente* buscarPorId(string id);
    int getCantidad();
    void vaciar();

    IteradorClientes crearIterador();
};

#endif
