#ifndef PISCINA_H
#define PISCINA_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


class Piscina : public EspacioDeportivo {
public:
    Piscina(string codigo, string nombre, int capacidad, double precioHora);

    string obtenerTipo();
    string obtenerCaracteristicas();
};

#endif
