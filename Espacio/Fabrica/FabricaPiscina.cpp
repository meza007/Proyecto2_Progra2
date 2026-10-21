#include "Espacio/Fabrica/FabricaPiscina.h"
#include "Espacio/Piscina.h"

EspacioDeportivo* FabricaPiscina::crearEspacio(string codigo, string nombre, int capacidad, double precioHora) {
    return new Piscina(codigo, nombre, capacidad, precioHora);
}
