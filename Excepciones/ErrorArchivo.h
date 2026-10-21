#ifndef ERRORARCHIVO_H
#define ERRORARCHIVO_H

#include <iostream>
using namespace std;

#include "Excepciones/ExcepcionCentroDeportivo.h"


// Se lanza cuando un archivo de datos no se puede abrir.
class ErrorArchivo : public ExcepcionCentroDeportivo {
public:
    ErrorArchivo(string nombreArchivo);
};

#endif
