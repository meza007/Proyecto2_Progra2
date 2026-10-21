#include "Espacio/Fabrica/FabricaCanchaFutbol.h"
#include "Espacio/CanchaFutbol.h"

EspacioDeportivo* FabricaCanchaFutbol::crearEspacio(string codigo, string nombre, int capacidad, double precioHora) {
    return new CanchaFutbol(codigo, nombre, capacidad, precioHora);
}
