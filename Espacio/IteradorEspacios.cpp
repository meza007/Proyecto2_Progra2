#include "Espacio/IteradorEspacios.h"

IteradorEspacios::IteradorEspacios(NodoEspacio *primero) {
    Actual = primero;
}

bool IteradorEspacios::hayMas() {
    return Actual != nullptr;
}

EspacioDeportivo* IteradorEspacios::siguiente() {
    if (Actual == nullptr) {
        return nullptr;
    }
    EspacioDeportivo *esp = Actual->getEspacio();
    Actual = Actual->getSiguiente();
    return esp;
}
