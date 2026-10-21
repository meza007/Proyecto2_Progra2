#include "Excepciones/ReservaNoEncontrada.h"

ReservaNoEncontrada::ReservaNoEncontrada(string codigo)
    : ExcepcionCentroDeportivo("No existe una reserva con codigo " + codigo + ".") {
}
