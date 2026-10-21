#ifndef EXCEPCIONCENTRODEPORTIVO_H
#define EXCEPCIONCENTRODEPORTIVO_H

#include <iostream>
#include <exception>
using namespace std;


// Base de las excepciones propias del sistema. Las clases de logica lanzan
// estas excepciones con un mensaje y Menu las atrapa y lo muestra, asi
// ninguna clase fuera de Menu imprime en pantalla.
class ExcepcionCentroDeportivo : public exception {
private:
    string Mensaje;

public:
    ExcepcionCentroDeportivo(string mensaje);

    const char* what() const noexcept override;
};

#endif
