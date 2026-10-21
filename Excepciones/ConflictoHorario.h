#ifndef CONFLICTOHORARIO_H
#define CONFLICTOHORARIO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class ConflictoHorario : public ExcepcionCentroDeportivo {
public:
    ConflictoHorario(string detalle);
};

#endif
