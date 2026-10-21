#include "Reserva/ListaReservas.h"

ListaReservas::ListaReservas() {
    Primero = nullptr;
    Cantidad = 0;
}

ListaReservas::~ListaReservas() {
    vaciar();
}

void ListaReservas::IngresaReserva(Reserva *res) {
    NodoReserva *nuevo = new NodoReserva(res, nullptr);
    Cantidad++;
    if (Primero == nullptr) {
        Primero = nuevo;
        return;
    }
    NodoReserva *actual = Primero;
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    actual->setSiguiente(nuevo);
}

Reserva* ListaReservas::buscarPorCodigo(string codigo) {
    NodoReserva *actual = Primero;
    while (actual != nullptr) {
        if (actual->getReserva()->getCodigo() == codigo) {
            return actual->getReserva();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

int ListaReservas::getCantidad() {
    return Cantidad;
}

int ListaReservas::contarActivas() {
    int total = 0;
    NodoReserva *actual = Primero;
    while (actual != nullptr) {
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
    while (actual != nullptr) {
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
    while (actual != nullptr) {
        if (actual->getReserva()->getCodigoEspacio() == codigoEspacio) {
            total++;
        }
        actual = actual->getSiguiente();
    }
    return total;
}

bool ListaReservas::tieneActivaEnEspacio(string codigoEspacio) {
    NodoReserva *actual = Primero;
    while (actual != nullptr) {
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
    while (actual != nullptr) {
        NodoReserva *siguiente = actual->getSiguiente();
        delete actual->getReserva();
        delete actual;
        actual = siguiente;
    }
    Primero = nullptr;
    Cantidad = 0;
}

IteradorReservas ListaReservas::crearIterador() {
    return IteradorReservas(Primero);
}
