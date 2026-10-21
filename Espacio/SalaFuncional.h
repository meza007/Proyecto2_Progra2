#ifndef SALAFUNCIONAL_H
#define SALAFUNCIONAL_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


class SalaFuncional : public EspacioDeportivo {
public:
    SalaFuncional(string codigo, string nombre, int capacidad, double precioHora);

    string obtenerTipo();
    string obtenerCaracteristicas();
};

#endif
