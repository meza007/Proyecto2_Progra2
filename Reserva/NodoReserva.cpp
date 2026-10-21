#include "Reserva/NodoReserva.h"

NodoReserva::NodoReserva() {
    Res = NULL;
    Sig = NULL;
}

NodoReserva::NodoReserva(Reserva *res, NodoReserva *sig) {
    Res = res;
    Sig = sig;
}

Reserva* NodoReserva::getReserva() {
    return Res;
}

void NodoReserva::setReserva(Reserva *res) {
    Res = res;
}

NodoReserva* NodoReserva::getSiguiente() {
    return Sig;
}

void NodoReserva::setSiguiente(NodoReserva *sig) {
    Sig = sig;
}
