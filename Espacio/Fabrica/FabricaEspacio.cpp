#include "Espacio/Fabrica/FabricaEspacio.h"
#include "Espacio/Fabrica/FabricaCanchaFutbol.h"
#include "Espacio/Fabrica/FabricaCanchaBaloncesto.h"
#include "Espacio/Fabrica/FabricaCanchaTenis.h"
#include "Espacio/Fabrica/FabricaPiscina.h"
#include "Espacio/Fabrica/FabricaSalaFuncional.h"
#include "Excepciones/DatoInvalido.h"

FabricaEspacio::~FabricaEspacio() {
}

EspacioDeportivo* FabricaEspacio::fabricar(string codigo, string nombre, int capacidad, double precioHora) {
    if (codigo.empty() || nombre.empty()) {
        throw DatoInvalido("El codigo y el nombre del espacio no pueden estar vacios.");
    }
    if (capacidad <= 0) {
        throw DatoInvalido("La capacidad del espacio debe ser mayor que cero.");
    }
    if (precioHora <= 0) {
        throw DatoInvalido("El precio por hora debe ser mayor que cero.");
    }
    return crearEspacio(codigo, nombre, capacidad, precioHora);
}

FabricaEspacio* FabricaEspacio::obtenerFabrica(string tipo) {
    if (tipo == "CanchaFutbol") {
        return new FabricaCanchaFutbol();
    }
    if (tipo == "CanchaBaloncesto") {
        return new FabricaCanchaBaloncesto();
    }
    if (tipo == "CanchaTenis") {
        return new FabricaCanchaTenis();
    }
    if (tipo == "Piscina") {
        return new FabricaPiscina();
    }
    if (tipo == "SalaFuncional") {
        return new FabricaSalaFuncional();
    }
    throw DatoInvalido("Tipo de espacio desconocido: " + tipo);
}

bool FabricaEspacio::tipoValido(string tipo) {
    return tipo == "CanchaFutbol" || tipo == "CanchaBaloncesto" || tipo == "CanchaTenis"
           || tipo == "Piscina" || tipo == "SalaFuncional";
}
