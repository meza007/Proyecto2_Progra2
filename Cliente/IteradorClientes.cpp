#include "Cliente/IteradorClientes.h"

IteradorClientes::IteradorClientes(NodoCliente *primero) {
    Actual = primero;
}

bool IteradorClientes::hayMas() {
    return Actual != nullptr;
}

Cliente* IteradorClientes::siguiente() {
    if (Actual == nullptr) {
        return nullptr;
    }
    Cliente *clie = Actual->getCliente();
    Actual = Actual->getSiguiente();
    return clie;
}
