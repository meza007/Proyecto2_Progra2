#ifndef FABRICACANCHAFUTBOL_H
#define FABRICACANCHAFUTBOL_H

#include <iostream>
using namespace std;

#include "Espacio/Fabrica/FabricaEspacio.h"

class FabricaCanchaFutbol : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
