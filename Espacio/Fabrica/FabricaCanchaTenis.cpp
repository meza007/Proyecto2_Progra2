#include "Espacio/Fabrica/FabricaCanchaTenis.h"
#include "Espacio/CanchaTenis.h"

EspacioDeportivo* FabricaCanchaTenis::crearEspacio(string codigo, string nombre, int capacidad, double precioHora) {
    return new CanchaTenis(codigo, nombre, capacidad, precioHora);
}
