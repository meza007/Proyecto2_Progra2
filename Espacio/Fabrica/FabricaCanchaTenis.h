#ifndef FABRICACANCHATENIS_H
#define FABRICACANCHATENIS_H

#include <iostream>
using namespace std;

#include "Espacio/Fabrica/FabricaEspacio.h"


 class FabricaCanchaTenis : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
