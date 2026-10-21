#ifndef ITERADORRESERVAS_H
#define ITERADORRESERVAS_H

#include <iostream>
using namespace std;

#include "Reserva/NodoReserva.h"


// Patron Iterator: permite recorrer ListaReservas sin conocer sus nodos.
// La lista (agregado) crea el iterador con crearIterador(); quien lo usa
// solo llama a hayMas() y siguiente().
class IteradorReservas {
private:
    NodoReserva *Actual;

public:
    IteradorReservas(NodoReserva *primero);

    bool hayMas();
    Reserva* siguiente();
};

#endif
