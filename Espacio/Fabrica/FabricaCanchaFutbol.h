#ifndef FABRICACANCHAFUTBOL_H
#define FABRICACANCHAFUTBOL_H
#include "Espacio/Fabrica/FabricaEspacio.h"
#include <iostream>
using namespace std;

class FabricaCanchaFutbol : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
