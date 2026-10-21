#include "Reserva/IteradorReservas.h"

IteradorReservas::IteradorReservas(NodoReserva *primero) {
    Actual = primero;
}

bool IteradorReservas::hayMas() {
    return Actual != NULL;
}

Reserva* IteradorReservas::siguiente() {
    if (Actual == NULL) {
        return NULL;
    }
    Reserva *res = Actual->getReserva();
    Actual = Actual->getSiguiente();
    return res;
}
