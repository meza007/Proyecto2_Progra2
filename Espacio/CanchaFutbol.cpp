#include "Espacio/CanchaFutbol.h"

CanchaFutbol::CanchaFutbol(string codigo, string nombre, int capacidad, double precioHora)
    : EspacioDeportivo(codigo, nombre, capacidad, precioHora) {
}

string CanchaFutbol::obtenerTipo() {
    return "CanchaFutbol";
}

string CanchaFutbol::obtenerCaracteristicas() {
    return "Cesped sintetico con porterias e iluminacion nocturna";
}
