#ifndef LISTARESERVAS_H
#define LISTARESERVAS_H

#include <iostream>
using namespace std;

#include "Reserva/NodoReserva.h"
#include "Reserva/IteradorReservas.h"


// Lista enlazada simple de reservas. Es duena de las Reserva que contiene
// y los libera en el destructor. Los nodos no se exponen: para recorrerla
// se usa el iterador (patron Iterator).
class ListaReservas {
private:
    NodoReserva *Primero;
    int Cantidad;

public:
    ListaReservas();
    ~ListaReservas();

    void IngresaReserva(Reserva *res);
    Reserva* buscarPorCodigo(string codigo);
    int getCantidad();
    int contarActivas();
    int contarPorCliente(string idCliente);
    int contarPorEspacio(string codigoEspacio);
    bool tieneActivaEnEspacio(string codigoEspacio);
    void vaciar();

    IteradorReservas crearIterador();
};

#endif
