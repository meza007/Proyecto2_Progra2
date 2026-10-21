#ifndef ITERADORESPACIOS_H
#define ITERADORESPACIOS_H

#include <iostream>
using namespace std;

#include "Espacio/NodoEspacio.h"

class IteradorEspacios {
private:
    NodoEspacio *Actual;

public:
    IteradorEspacios(NodoEspacio *primero);

    bool hayMas();
    EspacioDeportivo* siguiente();
};

#endif
