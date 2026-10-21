#include "Espacio/EspacioDeportivo.h"
#include <sstream>
#include <iomanip>

EspacioDeportivo::EspacioDeportivo(string codigo, string nombre, int capacidad, double precioHora) {
    Codigo = codigo;
    Nombre = nombre;
    Capacidad = capacidad;
    PrecioHora = precioHora;
}

EspacioDeportivo::~EspacioDeportivo() {
}

string EspacioDeportivo::getCodigo() {
    return Codigo;
}

string EspacioDeportivo::getNombre() {
    return Nombre;
}

int EspacioDeportivo::getCapacidad() {
    return Capacidad;
}

double EspacioDeportivo::getPrecioHora() {
    return PrecioHora;
}

double EspacioDeportivo::calcularCosto(double horas) {
    return PrecioHora * horas;
}

string EspacioDeportivo::toString() {
    stringstream ss;
    ss << "Codigo: " << Codigo
       << " | Tipo: " << obtenerTipo()
       << " | Nombre: " << Nombre
       << " | Capacidad: " << Capacidad
       << " | Precio/hora: " << fixed << setprecision(2) << PrecioHora
       << " | " << obtenerCaracteristicas();
    return ss.str();
}
