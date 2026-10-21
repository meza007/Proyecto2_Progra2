#include "Excepciones/EspacioDuplicado.h"

EspacioDuplicado::EspacioDuplicado(string codigo)
    : ExcepcionCentroDeportivo("Ya existe un espacio con codigo " + codigo + ".") {
}
