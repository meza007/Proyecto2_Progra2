#ifndef FABRICAESPACIO_H
#define FABRICAESPACIO_H
#include "Espacio/EspacioDeportivo.h"
#include <iostream>
using namespace std;


class FabricaEspacio {
protected:
    virtual EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora) = 0;

public:
    virtual ~FabricaEspacio();

    EspacioDeportivo* fabricar(string codigo, string nombre, int capacidad, double precioHora);

    static FabricaEspacio* obtenerFabrica(string tipo);
    static bool tipoValido(string tipo);
};

#endif
