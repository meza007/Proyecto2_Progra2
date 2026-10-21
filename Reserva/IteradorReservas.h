#ifndef ITERADORRESERVAS_H
#define ITERADORRESERVAS_H
#include "Reserva/NodoReserva.h"
#include <iostream>
using namespace std;

class IteradorReservas {
private:
    NodoReserva *Actual;

public:
    IteradorReservas(NodoReserva *primero);

    bool hayMas();
    Reserva* siguiente();
};

#endif
