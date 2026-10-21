#ifndef FABRICAESPACIO_H
#define FABRICAESPACIO_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


// Patron Factory Method (creador abstracto).
// fabricar() es la operacion comun: valida los datos y luego delega la
// creacion del objeto en crearEspacio(), el metodo fabrica que cada
// creador concreto (FabricaCanchaFutbol, FabricaPiscina, ...) implementa.
// Asi Archivo y la fachada crean espacios sin hacer "new" de las clases
// concretas, y agregar un tipo nuevo solo requiere una clase y su fabrica.
class FabricaEspacio {
protected:
    virtual EspacioDeportivo* crearEspacio(string codigo, string nombre, int capacidad, double precioHora) = 0;

public:
    virtual ~FabricaEspacio();

    EspacioDeportivo* fabricar(string codigo, string nombre, int capacidad, double precioHora);

    // Devuelve una fabrica nueva segun el tipo (el que llama la libera).
    // Lanza DatoInvalido si el tipo no existe.
    static FabricaEspacio* obtenerFabrica(string tipo);
    static bool tipoValido(string tipo);
};

#endif
