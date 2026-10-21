#include "Reserva/IteradorReservas.h"
IteradorReservas::IteradorReservas(NodoReserva *primero) {
    Actual = primero;
}

bool IteradorReservas::hayMas() {
    return Actual != nullptr;
}

Reserva* IteradorReservas::siguiente() {
    if (Actual == nullptr) {
        return nullptr;
    }
    Reserva *res = Actual->getReserva();
    Actual = Actual->getSiguiente();
    return res;
}
