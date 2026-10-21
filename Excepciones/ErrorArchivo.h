#ifndef ERRORARCHIVO_H
#define ERRORARCHIVO_H
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <iostream>
using namespace std;

class ErrorArchivo : public ExcepcionCentroDeportivo {
public:
    ErrorArchivo(string nombreArchivo);
};

#endif
