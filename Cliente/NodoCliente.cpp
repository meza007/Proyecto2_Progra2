#include "Cliente/NodoCliente.h"

NodoCliente::NodoCliente() {
    Clie = nullptr;
    Sig = nullptr;
}

NodoCliente::NodoCliente(Cliente *clie, NodoCliente *sig) {
    Clie = clie;
    Sig = sig;
}

Cliente* NodoCliente::getCliente() {
    return Clie;
}

void NodoCliente::setCliente(Cliente *clie) {
    Clie = clie;
}

NodoCliente* NodoCliente::getSiguiente() {
    return Sig;
}

void NodoCliente::setSiguiente(NodoCliente *sig) {
    Sig = sig;
}
