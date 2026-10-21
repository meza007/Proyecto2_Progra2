#ifndef FABRICASALAFUNCIONAL_H
#define FABRICASALAFUNCIONAL_H

#include <iostream>
using namespace std;

#include "Espacio/Fabrica/FabricaEspacio.h"

// Creador concreto del patron Factory Method: fabrica objetos SalaFuncional.
class FabricaSalaFuncional : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
