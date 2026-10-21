#include "Excepciones/ConflictoHorario.h"

ConflictoHorario::ConflictoHorario(string detalle)
    : ExcepcionCentroDeportivo("Conflicto de horario: " + detalle) {
}
