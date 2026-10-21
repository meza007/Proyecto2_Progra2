#include "Reserva/ListaReservas.h"

ListaReservas::ListaReservas() {
    Primero = NULL;
    Cantidad = 0;
}

ListaReservas::~ListaReservas() {
    vaciar();
}

void ListaReservas::IngresaReserva(Reserva *res) {
    NodoReserva *nuevo = new NodoReserva(res, NULL);
    Cantidad++;
    if (Primero == NULL) {
        Primero = nuevo;
        return;
    }
    NodoReserva *actual = Primero;
    while (actual->getSiguiente() != NULL) {
        actual = actual->getSiguiente();
    }
    actual->setSiguiente(nuevo);
}

Reserva* ListaReservas::buscarPorCodigo(string codigo) {
    NodoReserva *actual = Primero;
    while (actual != NULL) {
        if (actual->getReserva()->getCodigo() == codigo) {
            return actual->getReserva();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

int ListaReservas::getCantidad() {
    return Cantidad;
}

int ListaReservas::contarActivas() {
    int total = 0;
    NodoReserva *actual = Primero;
    while (actual != NULL) {
        if (actual->getReserva()->estaActiva()) {
            total++;
        }
        actual = actual->getSiguiente();
    }
    return total;
}

int ListaReservas::contarPorCliente(string idCliente) {
    int total = 0;
    NodoReserva *actual = Primero;
    while (actual != NULL) {
        if (actual->getReserva()->getIdCliente() == idCliente) {
            total++;
        }
        actual = actual->getSiguiente();
    }
    return total;
}

int ListaReservas::contarPorEspacio(string codigoEspacio) {
    int total = 0;
    NodoReserva *actual = Primero;
    while (actual != NULL) {
        if (actual->getReserva()->getCodigoEspacio() == codigoEspacio) {
            total++;
        }
        actual = actual->getSiguiente();
    }
    return total;
}

bool ListaReservas::tieneActivaEnEspacio(string codigoEspacio) {
    NodoReserva *actual = Primero;
    while (actual != NULL) {
        Reserva *res = actual->getReserva();
        if (res->estaActiva() && res->getCodigoEspacio() == codigoEspacio) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}

void ListaReservas::vaciar() {
    NodoReserva *actual = Primero;
    while (actual != NULL) {
        NodoReserva *siguiente = actual->getSiguiente();
        delete actual->getReserva();
        delete actual;
        actual = siguiente;
    }
    Primero = NULL;
    Cantidad = 0;
}

IteradorReservas ListaReservas::crearIterador() {
    return IteradorReservas(Primero);
}
