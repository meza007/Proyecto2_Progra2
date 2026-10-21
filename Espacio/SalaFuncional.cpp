#include "Espacio/SalaFuncional.h"

SalaFuncional::SalaFuncional(string codigo, string nombre, int capacidad, double precioHora)
    : EspacioDeportivo(codigo, nombre, capacidad, precioHora) {
}

string SalaFuncional::obtenerTipo() {
    return "SalaFuncional";
}

string SalaFuncional::obtenerCaracteristicas() {
    return "Equipo de entrenamiento funcional y espejos";
}
