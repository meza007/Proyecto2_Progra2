#include "Cliente/ListaClientes.h"

ListaClientes::ListaClientes() {
    Primero = NULL;
    Cantidad = 0;
}

ListaClientes::~ListaClientes() {
    vaciar();
}

void ListaClientes::IngresaCliente(Cliente *clie) {
    NodoCliente *nuevo = new NodoCliente(clie, NULL);
    Cantidad++;
    if (Primero == NULL) {
        Primero = nuevo;
        return;
    }
    NodoCliente *actual = Primero;
    while (actual->getSiguiente() != NULL) {
        actual = actual->getSiguiente();
    }
    actual->setSiguiente(nuevo);
}

Cliente* ListaClientes::buscarPorId(string id) {
    NodoCliente *actual = Primero;
    while (actual != NULL) {
        if (actual->getCliente()->getId() == id) {
            return actual->getCliente();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

int ListaClientes::getCantidad() {
    return Cantidad;
}

void ListaClientes::vaciar() {
    NodoCliente *actual = Primero;
    while (actual != NULL) {
        NodoCliente *siguiente = actual->getSiguiente();
        delete actual->getCliente();
        delete actual;
        actual = siguiente;
    }
    Primero = NULL;
    Cantidad = 0;
}

IteradorClientes ListaClientes::crearIterador() {
    return IteradorClientes(Primero);
}
