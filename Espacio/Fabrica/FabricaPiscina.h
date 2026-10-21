#ifndef FABRICAPISCINA_H
#define FABRICAPISCINA_H

#include <iostream>
using namespace std;

#include "Espacio/Fabrica/FabricaEspacio.h"


// Creador concreto del patron Factory Method: fabrica objetos Piscina.
class FabricaPiscina : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
