#ifndef FABRICACANCHABALONCESTO_H
#define FABRICACANCHABALONCESTO_H
#include "Espacio/Fabrica/FabricaEspacio.h"
#include <iostream>
using namespace std;

class FabricaCanchaBaloncesto : public FabricaEspacio {
protected:
    EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora);
};

#endif
