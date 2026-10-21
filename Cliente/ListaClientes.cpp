#include "Cliente/ListaClientes.h"

ListaClientes::ListaClientes() {
    Primero = nullptr;
    Cantidad = 0;
}

ListaClientes::~ListaClientes() {
    vaciar();
}

void ListaClientes::IngresaCliente(Cliente *clie) {
    NodoCliente *nuevo = new NodoCliente(clie, nullptr);
    Cantidad++;
    if (Primero == nullptr) {
        Primero = nuevo;
        return;
    }
    NodoCliente *actual = Primero;
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    actual->setSiguiente(nuevo);
}

Cliente* ListaClientes::buscarPorId(string id) {
    NodoCliente *actual = Primero;
    while (actual != nullptr) {
        if (actual->getCliente()->getId() == id) {
            return actual->getCliente();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

int ListaClientes::getCantidad() {
    return Cantidad;
}

void ListaClientes::vaciar() {
    NodoCliente *actual = Primero;
    while (actual != nullptr) {
        NodoCliente *siguiente = actual->getSiguiente();
        delete actual->getCliente();
        delete actual;
        actual = siguiente;
    }
    Primero = nullptr;
    Cantidad = 0;
}

IteradorClientes ListaClientes::crearIterador() {
    return IteradorClientes(Primero);
}
