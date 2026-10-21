#include "Espacio/Fabrica/FabricaCanchaBaloncesto.h"
#include "Espacio/CanchaBaloncesto.h"

EspacioDeportivo* FabricaCanchaBaloncesto::crearEspacio(string codigo, string nombre, int capacidad, double precioHora) {
    return new CanchaBaloncesto(codigo, nombre, capacidad, precioHora);
}
