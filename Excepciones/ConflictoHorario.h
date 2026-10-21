#ifndef CONFLICTOHORARIO_H
#define CONFLICTOHORARIO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza cuando una reserva choca con otra reserva activa del mismo espacio.
class ConflictoHorario : public ExcepcionCentroDeportivo {
public:
    ConflictoHorario(string detalle);
};

#endif
