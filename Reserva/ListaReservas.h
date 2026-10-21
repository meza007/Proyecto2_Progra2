#ifndef LISTARESERVAS_H
#define LISTARESERVAS_H
#include "Reserva/NodoReserva.h"
#include "Reserva/IteradorReservas.h"
#include <iostream>
using namespace std;

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
