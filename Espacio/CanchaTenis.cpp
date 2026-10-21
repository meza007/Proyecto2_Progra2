#include "Espacio/CanchaTenis.h"

CanchaTenis::CanchaTenis(string codigo, string nombre, int capacidad, double precioHora)
    : EspacioDeportivo(codigo, nombre, capacidad, precioHora) {
}

string CanchaTenis::obtenerTipo() {
    return "CanchaTenis";
}

string CanchaTenis::obtenerCaracteristicas() {
    return "Red reglamentaria y lineas para individuales y dobles";
}
