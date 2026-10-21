#ifndef EXCEPCIONCENTRODEPORTIVO_H
#define EXCEPCIONCENTRODEPORTIVO_H
#include <iostream>
#include <exception>
using namespace std;

class ExcepcionCentroDeportivo : public exception {
private:
    string Mensaje;

public:
    ExcepcionCentroDeportivo(string mensaje);

    const char* what() const noexcept override;
};

#endif
