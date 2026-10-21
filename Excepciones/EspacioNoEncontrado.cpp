#include "Excepciones/EspacioNoEncontrado.h"

EspacioNoEncontrado::EspacioNoEncontrado(string codigo)
    : ExcepcionCentroDeportivo("No existe un espacio con codigo " + codigo + ".") {
}
