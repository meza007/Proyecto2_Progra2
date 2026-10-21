#ifndef ESPACIODEPORTIVO_H
#define ESPACIODEPORTIVO_H

#include <iostream>
using namespace std;

class EspacioDeportivo {
protected:
    string Codigo;
    string Nombre;
    int Capacidad;
    double PrecioHora;

    EspacioDeportivo(string codigo, string nombre, int capacidad, double precioHora);

public:
    virtual ~EspacioDeportivo();

    virtual string obtenerTipo() = 0;
    virtual string obtenerCaracteristicas() = 0;

    string getCodigo();
    string getNombre();
    int getCapacidad();
    double getPrecioHora();

    double calcularCosto(double horas);

    virtual string toString();
};

#endif
