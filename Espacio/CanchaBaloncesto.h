#ifndef CANCHABALONCESTO_H
#define CANCHABALONCESTO_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


class CanchaBaloncesto : public EspacioDeportivo {
public:
    CanchaBaloncesto(string codigo, string nombre, int capacidad, double precioHora);

    string obtenerTipo();
    string obtenerCaracteristicas();
};

#endif
