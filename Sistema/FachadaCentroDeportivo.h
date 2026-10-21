#ifndef FACHADACENTRODEPORTIVO_H
#define FACHADACENTRODEPORTIVO_H

#include <iostream>
using namespace std;

#include "Sistema/AdministradorSistema.h"


// Patron Facade: punto de entrada unico para las operaciones del sistema.
// Menu solo habla con la fachada; la fachada coordina el administrador
// (Singleton), las listas, las fabricas de espacios y los archivos, valida
// las reglas de negocio y lanza excepciones propias cuando algo falla.
// Para mostrar colecciones entrega iteradores, nunca los nodos.
class FachadaCentroDeportivo {
private:
    AdministradorSistema *Admin;

    void validarTexto(string valor, string nombreCampo);
    void validarHorario(string fecha, string horaInicio, string horaFin);
    string generarCodigoReserva();

public:
    FachadaCentroDeportivo();

    // Archivos
    void cargarDatos(int &clientes, int &espacios, int &reservas);
    void guardarDatos();

    // Clientes
    void registrarCliente(string id, string nombre, string telefono, string correo);
    void modificarCliente(string id, string nombre, string telefono, string correo);
    Cliente* buscarCliente(string id);
    IteradorClientes iteradorClientes();

    // Espacios
    void registrarEspacio(string tipo, string codigo, string nombre, int capacidad, double precioHora);
    EspacioDeportivo* buscarEspacio(string codigo);
    bool estaOcupado(string codigoEspacio);
    bool consultarDisponibilidad(string codigoEspacio, string fecha, string horaInicio, string horaFin);
    IteradorEspacios iteradorEspacios();

    // Reservas
    Reserva* crearReserva(string idCliente, string codigoEspacio, string fecha, string horaInicio, string horaFin);
    Reserva* consultarReserva(string codigo);
    void cancelarReserva(string codigo);
    double calcularCostoReserva(Reserva *reserva);
    IteradorReservas iteradorReservas();

    // Reportes
    int totalReservas();
    int totalReservasActivas();
    Cliente* clienteConMasReservas(int &cantidad);
    EspacioDeportivo* espacioMasReservado(int &cantidad);
};

#endif
