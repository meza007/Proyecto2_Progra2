#ifndef LISTAESPACIOS_H
#define LISTAESPACIOS_H

#include <iostream>
using namespace std;

#include "Espacio/NodoEspacio.h"
#include "Espacio/IteradorEspacios.h"

class ListaEspacios {
private:
    NodoEspacio *Primero;
    int Cantidad;

public:
    ListaEspacios();
    ~ListaEspacios();

    void IngresaEspacio(EspacioDeportivo *esp);
    EspacioDeportivo* buscarPorCodigo(string codigo);
    int getCantidad();
    void vaciar();

    IteradorEspacios crearIterador();
};

#endif
