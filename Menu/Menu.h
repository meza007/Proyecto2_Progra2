#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

#include "Sistema/FachadaCentroDeportivo.h"


// Unica clase que interactua con el usuario: muestra los menus, lee las
// entradas y presenta resultados y errores. Toda operacion se delega en la
// fachada, y las colecciones se recorren solo mediante iteradores.
// La presentacion usa secuencias ANSI de color y marcos con caracteres ASCII
// (+, -, |, =) para que se vea bien en cualquier consola de Windows.
class Menu {
private:
    FachadaCentroDeportivo Fachada;

    // Ancho de los marcos de titulos y menus.
    static const int ANCHO_MARCO = 60;

    // Anchos de las columnas de cada tabla.
    static const int ANCHOS_CLIENTES[4];
    static const int ANCHOS_ESPACIOS[6];
    static const int ANCHOS_RESERVAS[8];

    // Colores ANSI
    const char* colorTitulo();
    const char* colorNumero();
    const char* colorTexto();
    const char* colorExito();
    const char* colorError();
    const char* colorAdvertencia();
    const char* colorNegrita();
    const char* colorReset();
    void activarColoresConsola();

    // Elementos de presentacion
    void mostrarBienvenida();
    void mostrarTitulo(string titulo);
    void mostrarOpcion(int numero, string texto);
    void mostrarPieMenu();
    void mostrarSeparador();
    void mostrarSubtitulo(string texto);
    void mostrarExito(string mensaje);
    void mostrarError(string mensaje);
    void mostrarAdvertencia(string mensaje);
    void mostrarDato(string etiqueta, string valor);
    void lineaCentrada(string texto, const char *color);
    void pausar();

    // Tablas
    string recortar(string texto, int ancho);
    string formatoMonto(double monto);
    void lineaTabla(const int anchos[], int columnas);
    void celda(string texto, int ancho, const char *color, bool derecha = false);
    void finFila();
    void encabezadoClientes();
    void filaCliente(Cliente *cliente);
    void encabezadoEspacios();
    void filaEspacio(EspacioDeportivo *espacio);
    void encabezadoReservas();
    void filaReserva(Reserva *reserva);

    // Lectura de datos
    string leerTexto(string mensaje);
    int leerEntero(string mensaje);
    double leerDouble(string mensaje);
    bool confirmar(string mensaje);

    void cargarDatos();
    void guardarDatos();

    void mostrarMenuPrincipal();
    void menuClientes();
    void menuEspacios();
    void menuReservas();
    void menuReportes();

    void registrarCliente();
    void modificarCliente();
    void buscarCliente();
    void listarClientes();

    void listarEspaciosPorEstado(bool ocupados);
    void buscarEspacio();
    void listarEspacios();
    void consultarDisponibilidad();
    void registrarEspacio();

    void crearReserva();
    void consultarReserva();
    void cancelarReserva();
    void listarReservas(bool soloActivas);

    void reporteTotalReservas();
    void reporteClienteConMasReservas();
    void reporteEspacioMasReservado();

public:
    void iniciar();
};

#endif
