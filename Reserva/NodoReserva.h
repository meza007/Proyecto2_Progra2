#ifndef NODORESERVA_H
#define NODORESERVA_H
#include "Reserva/Reserva.h"
#include <iostream>
using namespace std;

class NodoReserva {
private:
    Reserva *Res;
    NodoReserva *Sig;

public:
    NodoReserva();
    NodoReserva(Reserva *res, NodoReserva *sig);

    Reserva* getReserva();
    void setReserva(Reserva *res);

    NodoReserva* getSiguiente();
    void setSiguiente(NodoReserva *sig);
};

#endif
