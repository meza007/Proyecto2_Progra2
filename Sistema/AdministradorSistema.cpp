#include "Sistema/AdministradorSistema.h"
#include "Archivo/Archivo.h"

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
