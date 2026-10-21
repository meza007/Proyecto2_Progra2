#ifndef CANCHATENIS_H
#define CANCHATENIS_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


class CanchaTenis : public EspacioDeportivo {
public:
    CanchaTenis(string codigo, string nombre, int capacidad, double precioHora);

    string obtenerTipo();
    string obtenerCaracteristicas();
};

#endif
