#ifndef FABRICACANCHATENIS_H
#define FABRICACANCHATENIS_H
#include "Espacio/Fabrica/FabricaEspacio.h"
#include <iostream>
using namespace std;



 class FabricaCanchaTenis : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
