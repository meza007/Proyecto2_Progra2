#ifndef FABRICACANCHABALONCESTO_H
#define FABRICACANCHABALONCESTO_H

#include <iostream>
using namespace std;

#include "Espacio/Fabrica/FabricaEspacio.h"

class FabricaCanchaBaloncesto : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
