#include "Excepciones/ExcepcionCentroDeportivo.h"

ExcepcionCentroDeportivo::ExcepcionCentroDeportivo(string mensaje) {
    Mensaje = mensaje;
}

const char* ExcepcionCentroDeportivo::what() const noexcept {
    return Mensaje.c_str();
}
