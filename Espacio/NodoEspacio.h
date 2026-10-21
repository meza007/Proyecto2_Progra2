#ifndef NODOESPACIO_H
#define NODOESPACIO_H

#include <iostream>
using namespace std;

#include "Espacio/EspacioDeportivo.h"


class NodoEspacio {
private:
    EspacioDeportivo *Esp;
    NodoEspacio *Sig;

public:
    NodoEspacio();
    NodoEspacio(EspacioDeportivo *esp, NodoEspacio *sig);

    EspacioDeportivo* getEspacio();
    void setEspacio(EspacioDeportivo *esp);

    NodoEspacio* getSiguiente();
    void setSiguiente(NodoEspacio *sig);
};

#endif
