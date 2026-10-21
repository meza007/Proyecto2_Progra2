#include "Espacio/CanchaBaloncesto.h"

CanchaBaloncesto::CanchaBaloncesto(string codigo, string nombre, int capacidad, double precioHora)
    : EspacioDeportivo(codigo, nombre, capacidad, precioHora) {
}

string CanchaBaloncesto::obtenerTipo() {
    return "CanchaBaloncesto";
}

string CanchaBaloncesto::obtenerCaracteristicas() {
    return "Piso de duela con dos tableros reglamentarios";
}
