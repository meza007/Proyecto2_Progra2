#include "Sistema/AdministradorSistema.h"
#include "Archivo/Archivo.h"

// Las rutas son relativas a la carpeta desde donde se ejecuta el programa.
// CMake copia datos/ junto al ejecutable, asi funcionan tanto desde CLion
// (carpeta del build) como por consola desde la raiz del proyecto.
AdministradorSistema::AdministradorSistema() {
    Clientes = new ListaClientes();
    Espacios = new ListaEspacios();
    Reservas = new ListaReservas();
    ArchivoClientes = "datos/clientes.csv";
    ArchivoEspacios = "datos/espacios.csv";
    ArchivoReservas = "datos/reservas.csv";
}

AdministradorSistema::~AdministradorSistema() {
    delete Clientes;
    delete Espacios;
    delete Reservas;
}

// La instancia es una variable estatica local: se crea la primera vez que
// se llama a este metodo y se destruye automaticamente al terminar main.
AdministradorSistema* AdministradorSistema::obtenerInstancia() {
    static AdministradorSistema instancia;
    return &instancia;
}

ListaClientes* AdministradorSistema::getClientes() {
    return Clientes;
}

ListaEspacios* AdministradorSistema::getEspacios() {
    return Espacios;
}

ListaReservas* AdministradorSistema::getReservas() {
    return Reservas;
}

void AdministradorSistema::cargarDatos(int &clientes, int &espacios, int &reservas) {
    Clientes->vaciar();
    Espacios->vaciar();
    Reservas->vaciar();
    clientes = Archivo::cargarClientes(Clientes, ArchivoClientes);
    espacios = Archivo::cargarEspacios(Espacios, ArchivoEspacios);
    reservas = Archivo::cargarReservas(Reservas, ArchivoReservas);
}

void AdministradorSistema::guardarDatos() {
    Archivo::guardarClientes(Clientes, ArchivoClientes);
    Archivo::guardarEspacios(Espacios, ArchivoEspacios);
    Archivo::guardarReservas(Reservas, ArchivoReservas);
}
