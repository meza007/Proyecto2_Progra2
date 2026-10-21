#include "Espacio/Fabrica/FabricaSalaFuncional.h"
#include "Espacio/SalaFuncional.h"

EspacioDeportivo* FabricaSalaFuncional::crearEspacio(string codigo, string nombre, int capacidad, double precioHora) {
    return new SalaFuncional(codigo, nombre, capacidad, precioHora);
}
