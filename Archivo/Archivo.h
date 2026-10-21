#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
using namespace std;

#include "Cliente/ListaClientes.h"
#include "Espacio/ListaEspacios.h"
#include "Reserva/ListaReservas.h"

class Archivo {
public:
    static int cargarClientes(ListaClientes *lista, string nombreArchivo);
    static void guardarClientes(ListaClientes *lista, string nombreArchivo);

    static int cargarEspacios(ListaEspacios *lista, string nombreArchivo);
    static void guardarEspacios(ListaEspacios *lista, string nombreArchivo);

    static int cargarReservas(ListaReservas *lista, string nombreArchivo);
    static void guardarReservas(ListaReservas *lista, string nombreArchivo);

private:
    static string siguienteCampo(string &linea);
    static string quitarFinDeLinea(string linea);
};

#endif
