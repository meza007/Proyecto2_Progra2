#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;


// Representa a un cliente del centro deportivo. Solo guarda sus datos;
// las validaciones de negocio las hace la fachada y la interaccion con el
// usuario la hace Menu.
class Cliente {
private:
    string Id;
    string Nombre;
    string Telefono;
    string Correo;

public:
    Cliente(string id, string nombre, string telefono, string correo);

    string getId();

    string getNombre();
    void setNombre(string nombre);

    string getTelefono();
    void setTelefono(string telefono);

    string getCorreo();
    void setCorreo(string correo);

    string toString();
};

#endif
