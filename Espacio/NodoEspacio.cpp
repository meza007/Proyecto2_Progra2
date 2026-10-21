#include "Espacio/NodoEspacio.h"

NodoEspacio::NodoEspacio() {
    Esp = nullptr;
    Sig = nullptr;
}

NodoEspacio::NodoEspacio(EspacioDeportivo *esp, NodoEspacio *sig) {
    Esp = esp;
    Sig = sig;
}

EspacioDeportivo* NodoEspacio::getEspacio() {
    return Esp;
}

void NodoEspacio::setEspacio(EspacioDeportivo *esp) {
    Esp = esp;
}

NodoEspacio* NodoEspacio::getSiguiente() {
    return Sig;
}

void NodoEspacio::setSiguiente(NodoEspacio *sig) {
    Sig = sig;
}
