#include "Espacio/Piscina.h"

Piscina::Piscina(string codigo, string nombre, int capacidad, double precioHora)
    : EspacioDeportivo(codigo, nombre, capacidad, precioHora) {
}

string Piscina::obtenerTipo() {
    return "Piscina";
}

string Piscina::obtenerCaracteristicas() {
    return "Carriles demarcados y salvavidas en turno";
}
