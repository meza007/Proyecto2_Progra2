#include "Espacio/IteradorEspacios.h"

IteradorEspacios::IteradorEspacios(NodoEspacio *primero) {
    Actual = primero;
}

bool IteradorEspacios::hayMas() {
    return Actual != NULL;
}

EspacioDeportivo* IteradorEspacios::siguiente() {
    if (Actual == NULL) {
        return NULL;
    }
    EspacioDeportivo *esp = Actual->getEspacio();
    Actual = Actual->getSiguiente();
    return esp;
}
