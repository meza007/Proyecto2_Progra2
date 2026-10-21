#ifndef FABRICASALAFUNCIONAL_H
#define FABRICASALAFUNCIONAL_H
#include "Espacio/Fabrica/FabricaEspacio.h"
#include <iostream>
using namespace std;

class FabricaSalaFuncional : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
