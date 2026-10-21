#ifndef ADMINISTRADORSISTEMA_H
#define ADMINISTRADORSISTEMA_H

#include <iostream>
using namespace std;

#include "Cliente/ListaClientes.h"
#include "Espacio/ListaEspacios.h"
#include "Reserva/ListaReservas.h"

class AdministradorSistema {
private:
    ListaClientes *Clientes;
    ListaEspacios *Espacios;
    ListaReservas *Reservas;

    string ArchivoClientes;
    string ArchivoEspacios;
    string ArchivoReservas;

    AdministradorSistema();

public:
    AdministradorSistema(const AdministradorSistema &) = delete;
    AdministradorSistema& operator=(const AdministradorSistema &) = delete;
    ~AdministradorSistema();

    static AdministradorSistema* obtenerInstancia();

    ListaClientes* getClientes();
    ListaEspacios* getEspacios();
    ListaReservas* getReservas();

    // Vacia las listas y vuelve a leer los tres archivos.
    // Lanza ErrorArchivo si alguno no se puede abrir.
    void cargarDatos(int &clientes, int &espacios, int &reservas);
    void guardarDatos();
};

#endif
