#include "Cliente/Cliente.h"
#include <sstream>

Cliente::Cliente(string id, string nombre, string telefono, string correo) {
    Id = id;
    Nombre = nombre;
    Telefono = telefono;
    Correo = correo;
}

string Cliente::getId() {
    return Id;
}

string Cliente::getNombre() {
    return Nombre;
}

void Cliente::setNombre(string nombre) {
    Nombre = nombre;
}

string Cliente::getTelefono() {
    return Telefono;
}

void Cliente::setTelefono(string telefono) {
    Telefono = telefono;
}

string Cliente::getCorreo() {
    return Correo;
}

void Cliente::setCorreo(string correo) {
    Correo = correo;
}

string Cliente::toString() {
    stringstream ss;
    ss << "Id: " << Id
       << " | Nombre: " << Nombre
       << " | Telefono: " << Telefono
       << " | Correo: " << Correo;
    return ss.str();
}
