#ifndef FABRICAPISCINA_H
#define FABRICAPISCINA_H
#include "Espacio/Fabrica/FabricaEspacio.h"
#include <iostream>
using namespace std;


class FabricaPiscina : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
