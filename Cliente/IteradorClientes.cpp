#include "Cliente/IteradorClientes.h"

IteradorClientes::IteradorClientes(NodoCliente *primero) {
    Actual = primero;
}

bool IteradorClientes::hayMas() {
    return Actual != NULL;
}

Cliente* IteradorClientes::siguiente() {
    if (Actual == NULL) {
        return NULL;
    }
    Cliente *clie = Actual->getCliente();
    Actual = Actual->getSiguiente();
    return clie;
}
