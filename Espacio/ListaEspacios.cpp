#include "Espacio/ListaEspacios.h"

ListaEspacios::ListaEspacios() {
    Primero = NULL;
    Cantidad = 0;
}

ListaEspacios::~ListaEspacios() {
    vaciar();
}

void ListaEspacios::IngresaEspacio(EspacioDeportivo *esp) {
    NodoEspacio *nuevo = new NodoEspacio(esp, NULL);
    Cantidad++;
    if (Primero == NULL) {
        Primero = nuevo;
        return;
    }
    NodoEspacio *actual = Primero;
    while (actual->getSiguiente() != NULL) {
        actual = actual->getSiguiente();
    }
    actual->setSiguiente(nuevo);
}

EspacioDeportivo* ListaEspacios::buscarPorCodigo(string codigo) {
    NodoEspacio *actual = Primero;
    while (actual != NULL) {
        if (actual->getEspacio()->getCodigo() == codigo) {
            return actual->getEspacio();
        }
        actual = actual->getSiguiente();
    }
    return NULL;
}

int ListaEspacios::getCantidad() {
    return Cantidad;
}

void ListaEspacios::vaciar() {
    NodoEspacio *actual = Primero;
    while (actual != NULL) {
        NodoEspacio *siguiente = actual->getSiguiente();
        delete actual->getEspacio();
        delete actual;
        actual = siguiente;
    }
    Primero = NULL;
    Cantidad = 0;
}

IteradorEspacios ListaEspacios::crearIterador() {
    return IteradorEspacios(Primero);
}
