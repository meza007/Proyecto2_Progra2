#include "Espacio/ListaEspacios.h"

ListaEspacios::ListaEspacios() {
    Primero = nullptr;
    Cantidad = 0;
}

ListaEspacios::~ListaEspacios() {
    vaciar();
}

void ListaEspacios::IngresaEspacio(EspacioDeportivo *esp) {
    NodoEspacio *nuevo = new NodoEspacio(esp, nullptr);
    Cantidad++;
    if (Primero == nullptr) {
        Primero = nuevo;
        return;
    }
    NodoEspacio *actual = Primero;
    while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
    }
    actual->setSiguiente(nuevo);
}

EspacioDeportivo* ListaEspacios::buscarPorCodigo(string codigo) {
    NodoEspacio *actual = Primero;
    while (actual != nullptr) {
        if (actual->getEspacio()->getCodigo() == codigo) {
            return actual->getEspacio();
        }
        actual = actual->getSiguiente();
    }
    return nullptr;
}

int ListaEspacios::getCantidad() {
    return Cantidad;
}

void ListaEspacios::vaciar() {
    NodoEspacio *actual = Primero;
    while (actual != nullptr) {
        NodoEspacio *siguiente = actual->getSiguiente();
        delete actual->getEspacio();
        delete actual;
        actual = siguiente;
    }
    Primero = nullptr;
    Cantidad = 0;
}

IteradorEspacios ListaEspacios::crearIterador() {
    return IteradorEspacios(Primero);
}
