#ifndef CANCHAFUTBOL_H
#define CANCHAFUTBOL_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


class CanchaFutbol : public EspacioDeportivo {
public:
    CanchaFutbol(string codigo, string nombre, int capacidad, double precioHora);

    string obtenerTipo();
    string obtenerCaracteristicas();
};

#endif
