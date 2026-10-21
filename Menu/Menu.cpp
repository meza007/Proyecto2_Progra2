#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif

#include "Menu/Menu.h"
#include "Excepciones/ExcepcionCentroDeportivo.h"
#include <cstdlib>
#include <iomanip>
#include <sstream>
#ifdef _WIN32
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
const int Menu::ANCHOS_CLIENTES[4] = { 14, 26, 10, 28 };
const int Menu::ANCHOS_ESPACIOS[6] = { 6, 16, 26, 6, 11, 10 };
const int Menu::ANCHOS_RESERVAS[8] = { 6, 12, 7, 10, 6, 5, 11, 9 };

const char* Menu::colorTitulo() {
    return "\033[1;96m"; // cian brillante en negrita
}
const char* Menu::colorNumero() {
    return "\033[1;93m"; // amarillo
}
const char* Menu::colorTexto() {
    return "\033[97m"; // blanco
}
const char* Menu::colorExito() {
    return "\033[92m"; // verde
}
const char* Menu::colorError() {
    return "\033[91m"; // rojo
}
const char* Menu::colorAdvertencia() {
    return "\033[93m"; // amarillo
}
const char* Menu::colorNegrita() {
    return "\033[1m";
}

const char* Menu::colorReset() {
    return "\033[0m";
}

void Menu::activarColoresConsola() {

    HANDLE salida = GetStdHandle(STD_OUTPUT_HANDLE);
    if (salida == INVALID_HANDLE_VALUE) {
        return;
    }
    DWORD modo = 0;
    if (!GetConsoleMode(salida, &modo)) {
        return;
    }
    SetConsoleMode(salida, modo | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif
}

void Menu::lineaCentrada(string texto, const char *color) {
    int interior = ANCHO_MARCO - 2;
    int izquierda = (interior - (int) texto.size()) / 2;
    if (izquierda < 0) {
        izquierda = 0;
    }
    int derecha = interior - izquierda - (int) texto.size();
    if (derecha < 0) {
        derecha = 0;
    }
    cout << colorTitulo() << "|" << colorReset()
         << string(izquierda, ' ') << color << texto << colorReset() << string(derecha, ' ')
         << colorTitulo() << "|" << colorReset() << endl;
}

void Menu::mostrarBienvenida() {
    string borde = "+" + string(ANCHO_MARCO - 2, '=') + "+";
    cout << endl;
    cout << colorTitulo() << borde << colorReset() << endl;
    lineaCentrada("", colorTitulo());
    lineaCentrada("C E N T R O   D E P O R T I V O", colorTitulo());
    lineaCentrada("M U L T I U S O", colorTitulo());
    lineaCentrada("", colorTitulo());
    lineaCentrada(string(36, '-'), colorTitulo());
    lineaCentrada("Sistema de Gestion de Reservas", colorTexto());
    lineaCentrada("Clientes  -  Espacios  -  Reservas", colorTexto());
    lineaCentrada("", colorTitulo());
    cout << colorTitulo() << borde << colorReset() << endl;
    cout << endl;
}

void Menu::mostrarTitulo(string titulo) {
    string borde = "+" + string(ANCHO_MARCO - 2, '=') + "+";
    cout << endl;
    cout << colorTitulo() << borde << colorReset() << endl;
    lineaCentrada(titulo, colorTitulo());
    cout << colorTitulo() << borde << colorReset() << endl;
}

void Menu::mostrarOpcion(int numero, string texto) {
    cout << colorTitulo() << "|" << colorReset() << "   "
         << colorNumero() << setw(2) << right << numero << "." << colorReset() << " "
         << colorTexto() << left << setw(ANCHO_MARCO - 9) << texto << colorReset()
         << colorTitulo() << "|" << colorReset() << endl;
}

void Menu::mostrarPieMenu() {
    cout << colorTitulo() << "+" << string(ANCHO_MARCO - 2, '-') << "+" << colorReset() << endl;
}

void Menu::mostrarSeparador() {
    cout << endl << colorTitulo() << string(ANCHO_MARCO, '-') << colorReset() << endl;
}

void Menu::mostrarSubtitulo(string texto) {
    cout << endl << colorTitulo() << ">> " << texto << colorReset() << endl;
}

void Menu::mostrarExito(string mensaje) {
    cout << colorExito() << "[OK] " << mensaje << colorReset() << endl;
}

void Menu::mostrarError(string mensaje) {
    cout << colorError() << "[ERROR] " << mensaje << colorReset() << endl;
}

void Menu::mostrarAdvertencia(string mensaje) {
    cout << colorAdvertencia() << "[!] " << mensaje << colorReset() << endl;
}

void Menu::mostrarDato(string etiqueta, string valor) {
    cout << "  " << colorNegrita() << left << setw(18) << etiqueta << colorReset()
         << colorTexto() << valor << colorReset() << endl;
}

void Menu::pausar() {
    if (!cin) {
        return;
    }
    cout << endl << colorTexto() << "Presione ENTER para continuar..." << colorReset();
    string linea;
    getline(cin, linea);
}

string Menu::recortar(string texto, int ancho) {
    if ((int) texto.size() <= ancho) {
        return texto;
    }
    if (ancho <= 2) {
        return texto.substr(0, ancho);
    }
    return texto.substr(0, ancho - 2) + "..";
}

string Menu::formatoMonto(double monto) {
    stringstream ss;
    ss << fixed << setprecision(2) << monto;
    return ss.str();
}

void Menu::lineaTabla(const int anchos[], int columnas) {
    cout << colorTitulo() << "+";
    for (int i = 0; i < columnas; i++) {
        cout << string(anchos[i] + 2, '-') << "+";
    }
    cout << colorReset() << endl;
}

void Menu::celda(string texto, int ancho, const char *color, bool derecha) {
    cout << colorTitulo() << "| " << colorReset() << color;
    if (derecha) {
        cout << right;
    } else {
        cout << left;
    }
    cout << setw(ancho) << recortar(texto, ancho) << colorReset() << " ";
    cout << left;
}

void Menu::finFila() {
    cout << colorTitulo() << "|" << colorReset() << endl;
}

void Menu::encabezadoClientes() {
    lineaTabla(ANCHOS_CLIENTES, 4);
    celda("Identificacion", ANCHOS_CLIENTES[0], colorNegrita());
    celda("Nombre", ANCHOS_CLIENTES[1], colorNegrita());
    celda("Telefono", ANCHOS_CLIENTES[2], colorNegrita());
    celda("Correo", ANCHOS_CLIENTES[3], colorNegrita());
    finFila();
    lineaTabla(ANCHOS_CLIENTES, 4);
}

void Menu::filaCliente(Cliente *cliente) {
    celda(cliente->getId(), ANCHOS_CLIENTES[0], colorTexto());
    celda(cliente->getNombre(), ANCHOS_CLIENTES[1], colorTexto());
    celda(cliente->getTelefono(), ANCHOS_CLIENTES[2], colorTexto());
    celda(cliente->getCorreo(), ANCHOS_CLIENTES[3], colorTexto());
    finFila();
}

void Menu::encabezadoEspacios() {
    lineaTabla(ANCHOS_ESPACIOS, 6);
    celda("Codigo", ANCHOS_ESPACIOS[0], colorNegrita());
    celda("Tipo", ANCHOS_ESPACIOS[1], colorNegrita());
    celda("Nombre", ANCHOS_ESPACIOS[2], colorNegrita());
    celda("Capac.", ANCHOS_ESPACIOS[3], colorNegrita(), true);
    celda("Precio/hora", ANCHOS_ESPACIOS[4], colorNegrita(), true);
    celda("Estado", ANCHOS_ESPACIOS[5], colorNegrita());
    finFila();
    lineaTabla(ANCHOS_ESPACIOS, 6);
}

void Menu::filaEspacio(EspacioDeportivo *espacio) {
    bool ocupado = Fachada.estaOcupado(espacio->getCodigo());
    celda(espacio->getCodigo(), ANCHOS_ESPACIOS[0], colorTexto());
    celda(espacio->obtenerTipo(), ANCHOS_ESPACIOS[1], colorTexto());
    celda(espacio->getNombre(), ANCHOS_ESPACIOS[2], colorTexto());
    celda(to_string(espacio->getCapacidad()), ANCHOS_ESPACIOS[3], colorTexto(), true);
    celda(formatoMonto(espacio->getPrecioHora()), ANCHOS_ESPACIOS[4], colorTexto(), true);
    if (ocupado) {
        celda("Ocupado", ANCHOS_ESPACIOS[5], colorAdvertencia());
    } else {
        celda("Disponible", ANCHOS_ESPACIOS[5], colorExito());
    }
    finFila();
}

void Menu::encabezadoReservas() {
    lineaTabla(ANCHOS_RESERVAS, 8);
    celda("Codigo", ANCHOS_RESERVAS[0], colorNegrita());
    celda("Cliente", ANCHOS_RESERVAS[1], colorNegrita());
    celda("Espacio", ANCHOS_RESERVAS[2], colorNegrita());
    celda("Fecha", ANCHOS_RESERVAS[3], colorNegrita());
    celda("Inicio", ANCHOS_RESERVAS[4], colorNegrita());
    celda("Fin", ANCHOS_RESERVAS[5], colorNegrita());
    celda("Costo", ANCHOS_RESERVAS[6], colorNegrita(), true);
    celda("Estado", ANCHOS_RESERVAS[7], colorNegrita());
    finFila();
    lineaTabla(ANCHOS_RESERVAS, 8);
}

void Menu::filaReserva(Reserva *reserva) {
    celda(reserva->getCodigo(), ANCHOS_RESERVAS[0], colorTexto());
    celda(reserva->getIdCliente(), ANCHOS_RESERVAS[1], colorTexto());
    celda(reserva->getCodigoEspacio(), ANCHOS_RESERVAS[2], colorTexto());
    celda(reserva->getFecha(), ANCHOS_RESERVAS[3], colorTexto());
    celda(reserva->getHoraInicio(), ANCHOS_RESERVAS[4], colorTexto());
    celda(reserva->getHoraFin(), ANCHOS_RESERVAS[5], colorTexto());
    celda(formatoMonto(Fachada.calcularCostoReserva(reserva)), ANCHOS_RESERVAS[6], colorTexto(), true);
    if (reserva->estaActiva()) {
        celda(reserva->getEstadoTexto(), ANCHOS_RESERVAS[7], colorExito());
    } else {
        celda(reserva->getEstadoTexto(), ANCHOS_RESERVAS[7], colorError());
    }
    finFila();
}

string Menu::leerTexto(string mensaje) {
    cout << colorTexto() << mensaje << colorReset();
    string linea;
    if (!getline(cin, linea)) {
        return "";
    }
    size_t inicio = linea.find_first_not_of(" \t\r");
    if (inicio == string::npos) {
        return "";
    }
    size_t fin = linea.find_last_not_of(" \t\r");
    return linea.substr(inicio, fin - inicio + 1);
}

int Menu::leerEntero(string mensaje) {
    while (true) {
        string texto = leerTexto(mensaje);
        if (!cin) {
            return 0;
        }
        char *resto = NULL;
        long valor = strtol(texto.c_str(), &resto, 10);
        if (!texto.empty() && *resto == '\0') {
            return (int) valor;
        }
        mostrarError("Debe ingresar un numero entero.");
    }
}

double Menu::leerDouble(string mensaje) {
    while (true) {
        string texto = leerTexto(mensaje);
        if (!cin) {
            return 0;
        }
        char *resto = NULL;
        double valor = strtod(texto.c_str(), &resto);
        if (!texto.empty() && *resto == '\0') {
            return valor;
        }
        mostrarError("Debe ingresar un numero.");
    }
}

bool Menu::confirmar(string mensaje) {
    cout << colorAdvertencia() << "[?] " << colorReset();
    string respuesta = leerTexto(mensaje + " (s/n): ");
    return respuesta == "s" || respuesta == "S";
}

void Menu::cargarDatos() {
    try {
        int clientes = 0;
        int espacios = 0;
        int reservas = 0;
        Fachada.cargarDatos(clientes, espacios, reservas);
        mostrarExito("Datos cargados: " + to_string(clientes) + " clientes, "
                     + to_string(espacios) + " espacios, " + to_string(reservas) + " reservas.");
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::guardarDatos() {
    try {
        Fachada.guardarDatos();
        mostrarExito("Datos guardados correctamente.");
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::iniciar() {
    activarColoresConsola();
    mostrarBienvenida();
    cargarDatos();
    pausar();
    int opcion = -1;
    while (opcion != 0) {
        mostrarMenuPrincipal();
        opcion = leerEntero("Seleccione una opcion: ");
        if (!cin) {
            break;
        }
        mostrarSeparador();
        switch (opcion) {
            case 1:
                menuClientes();
                break;
            case 2:
                menuEspacios();
                break;
            case 3:
                menuReservas();
                break;
            case 4:
                menuReportes();
                break;
            case 5:
                guardarDatos();
                pausar();
                break;
            case 6:
                mostrarAdvertencia("Se perderan los cambios no guardados.");
                if (confirmar("Desea continuar?")) {
                    cargarDatos();
                }
                pausar();
                break;
            case 0:
                if (confirmar("Desea guardar los cambios antes de salir?")) {
                    guardarDatos();
                }
                cout << endl << colorTitulo() << "Hasta pronto." << colorReset() << endl;
                break;
            default:
                mostrarError("Opcion invalida.");
                pausar();
        }
    }
}

void Menu::mostrarMenuPrincipal() {
    mostrarTitulo("CENTRO DEPORTIVO MULTIUSO - RESERVAS");
    mostrarOpcion(1, "Gestion de Clientes");
    mostrarOpcion(2, "Gestion de Espacios");
    mostrarOpcion(3, "Gestion de Reservas");
    mostrarOpcion(4, "Reportes");
    mostrarOpcion(5, "Guardar datos");
    mostrarOpcion(6, "Cargar datos");
    mostrarOpcion(0, "Salir");
    mostrarPieMenu();
}

void Menu::menuClientes() {
    int opcion = -1;
    while (opcion != 0 && cin) {
        mostrarTitulo("GESTION DE CLIENTES");
        mostrarOpcion(1, "Registrar cliente");
        mostrarOpcion(2, "Modificar cliente");
        mostrarOpcion(3, "Buscar cliente por identificacion");
        mostrarOpcion(4, "Listar clientes");
        mostrarOpcion(0, "Volver");
        mostrarPieMenu();
        opcion = leerEntero("Seleccione una opcion: ");
        if (opcion == 0 || !cin) {
            break;
        }
        mostrarSeparador();
        switch (opcion) {
            case 1: registrarCliente(); break;
            case 2: modificarCliente(); break;
            case 3: buscarCliente(); break;
            case 4: listarClientes(); break;
            default: mostrarError("Opcion invalida.");
        }
        pausar();
    }
}

void Menu::registrarCliente() {
    mostrarSubtitulo("Registrar cliente");
    string id = leerTexto("Identificacion: ");
    string nombre = leerTexto("Nombre: ");
    string telefono = leerTexto("Telefono: ");
    string correo = leerTexto("Correo: ");
    try {
        Fachada.registrarCliente(id, nombre, telefono, correo);
        mostrarExito("Cliente registrado correctamente.");
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::modificarCliente() {
    mostrarSubtitulo("Modificar cliente");
    string id = leerTexto("Identificacion del cliente a modificar: ");
    try {
        Cliente *cliente = Fachada.buscarCliente(id);
        cout << endl << colorNegrita() << "Datos actuales:" << colorReset() << endl;
        encabezadoClientes();
        filaCliente(cliente);
        lineaTabla(ANCHOS_CLIENTES, 4);
        mostrarAdvertencia("Deje un campo vacio para conservar su valor.");
        string nombre = leerTexto("Nuevo nombre: ");
        string telefono = leerTexto("Nuevo telefono: ");
        string correo = leerTexto("Nuevo correo: ");
        if (nombre.empty()) {
            nombre = cliente->getNombre();
        }
        if (telefono.empty()) {
            telefono = cliente->getTelefono();
        }
        if (correo.empty()) {
            correo = cliente->getCorreo();
        }
        Fachada.modificarCliente(id, nombre, telefono, correo);
        mostrarExito("Cliente modificado correctamente.");
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::buscarCliente() {
    mostrarSubtitulo("Buscar cliente por identificacion");
    string id = leerTexto("Identificacion: ");
    try {
        Cliente *cliente = Fachada.buscarCliente(id);
        cout << endl;
        encabezadoClientes();
        filaCliente(cliente);
        lineaTabla(ANCHOS_CLIENTES, 4);
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::listarClientes() {
    mostrarSubtitulo("Clientes registrados");
    IteradorClientes it = Fachada.iteradorClientes();
    if (!it.hayMas()) {
        mostrarAdvertencia("No hay clientes registrados.");
        return;
    }
    int mostrados = 0;
    encabezadoClientes();
    while (it.hayMas()) {
        filaCliente(it.siguiente());
        mostrados++;
    }
    lineaTabla(ANCHOS_CLIENTES, 4);
    cout << colorNegrita() << "Total: " << mostrados << " cliente(s)." << colorReset() << endl;
}

void Menu::menuEspacios() {
    int opcion = -1;
    while (opcion != 0 && cin) {
        mostrarTitulo("GESTION DE ESPACIOS");
        mostrarOpcion(1, "Mostrar espacios disponibles");
        mostrarOpcion(2, "Mostrar espacios ocupados");
        mostrarOpcion(3, "Buscar espacio por codigo");
        mostrarOpcion(4, "Listar todos los espacios");
        mostrarOpcion(5, "Consultar disponibilidad por horario");
        mostrarOpcion(6, "Registrar espacio");
        mostrarOpcion(0, "Volver");
        mostrarPieMenu();
        opcion = leerEntero("Seleccione una opcion: ");
        if (opcion == 0 || !cin) {
            break;
        }
        mostrarSeparador();
        switch (opcion) {
            case 1: listarEspaciosPorEstado(false); break;
            case 2: listarEspaciosPorEstado(true); break;
            case 3: buscarEspacio(); break;
            case 4: listarEspacios(); break;
            case 5: consultarDisponibilidad(); break;
            case 6: registrarEspacio(); break;
            default: mostrarError("Opcion invalida.");
        }
        pausar();
    }
}

void Menu::listarEspaciosPorEstado(bool ocupados) {
    if (ocupados) {
        mostrarSubtitulo("Espacios ocupados (con reservas activas)");
    } else {
        mostrarSubtitulo("Espacios disponibles (sin reservas activas)");
    }
    int mostrados = 0;
    IteradorEspacios it = Fachada.iteradorEspacios();
    while (it.hayMas()) {
        EspacioDeportivo *e = it.siguiente();
        if (Fachada.estaOcupado(e->getCodigo()) == ocupados) {
            if (mostrados == 0) {
                encabezadoEspacios();
            }
            filaEspacio(e);
            mostrados++;
        }
    }
    if (mostrados == 0) {
        mostrarAdvertencia("No hay espacios en este estado.");
        return;
    }
    lineaTabla(ANCHOS_ESPACIOS, 6);
    cout << colorNegrita() << "Total: " << mostrados << " espacio(s)." << colorReset() << endl;
}

void Menu::buscarEspacio() {
    mostrarSubtitulo("Buscar espacio por codigo");
    string codigo = leerTexto("Codigo del espacio: ");
    try {
        EspacioDeportivo *e = Fachada.buscarEspacio(codigo);
        cout << endl;
        encabezadoEspacios();
        filaEspacio(e);
        lineaTabla(ANCHOS_ESPACIOS, 6);
        mostrarDato("Caracteristicas:", e->obtenerCaracteristicas());
        if (Fachada.estaOcupado(codigo)) {
            mostrarAdvertencia("Estado: ocupado (tiene reservas activas).");
        } else {
            mostrarExito("Estado: disponible (sin reservas activas).");
        }
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::listarEspacios() {
    mostrarSubtitulo("Espacios deportivos");
    IteradorEspacios it = Fachada.iteradorEspacios();
    if (!it.hayMas()) {
        mostrarAdvertencia("No hay espacios registrados.");
        return;
    }
    int mostrados = 0;
    encabezadoEspacios();
    while (it.hayMas()) {
        filaEspacio(it.siguiente());
        mostrados++;
    }
    lineaTabla(ANCHOS_ESPACIOS, 6);
    cout << colorNegrita() << "Total: " << mostrados << " espacio(s)." << colorReset() << endl;
}

void Menu::consultarDisponibilidad() {
    mostrarSubtitulo("Consultar disponibilidad por horario");
    string codigo = leerTexto("Codigo del espacio: ");
    string fecha = leerTexto("Fecha (AAAA-MM-DD): ");
    string inicio = leerTexto("Hora de inicio (HH:MM): ");
    string fin = leerTexto("Hora de fin (HH:MM): ");
    try {
        if (Fachada.consultarDisponibilidad(codigo, fecha, inicio, fin)) {
            mostrarExito("El espacio " + codigo + " esta disponible en ese horario.");
        } else {
            mostrarAdvertencia("El espacio " + codigo + " NO esta disponible en ese horario.");
        }
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::registrarEspacio() {
    mostrarSubtitulo("Registrar espacio");
    cout << colorNegrita() << "Tipos de espacio:" << colorReset() << endl;
    mostrarOpcion(1, "Cancha de futbol");
    mostrarOpcion(2, "Cancha de baloncesto");
    mostrarOpcion(3, "Cancha de tenis");
    mostrarOpcion(4, "Piscina");
    mostrarOpcion(5, "Sala funcional");
    mostrarPieMenu();
    int opcion = leerEntero("Seleccione el tipo: ");
    string tipos[5] = { "CanchaFutbol", "CanchaBaloncesto", "CanchaTenis", "Piscina", "SalaFuncional" };
    if (opcion < 1 || opcion > 5) {
        mostrarError("Tipo invalido.");
        return;
    }
    string codigo = leerTexto("Codigo: ");
    string nombre = leerTexto("Nombre: ");
    int capacidad = leerEntero("Capacidad (personas): ");
    double precio = leerDouble("Precio por hora: ");
    try {
        Fachada.registrarEspacio(tipos[opcion - 1], codigo, nombre, capacidad, precio);
        mostrarExito("Espacio registrado correctamente.");
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::menuReservas() {
    int opcion = -1;
    while (opcion != 0 && cin) {
        mostrarTitulo("GESTION DE RESERVAS");
        mostrarOpcion(1, "Crear reserva");
        mostrarOpcion(2, "Consultar reserva");
        mostrarOpcion(3, "Cancelar reserva");
        mostrarOpcion(4, "Listar reservas activas");
        mostrarOpcion(5, "Listar todas las reservas");
        mostrarOpcion(0, "Volver");
        mostrarPieMenu();
        opcion = leerEntero("Seleccione una opcion: ");
        if (opcion == 0 || !cin) {
            break;
        }
        mostrarSeparador();
        switch (opcion) {
            case 1: crearReserva(); break;
            case 2: consultarReserva(); break;
            case 3: cancelarReserva(); break;
            case 4: listarReservas(true); break;
            case 5: listarReservas(false); break;
            default: mostrarError("Opcion invalida.");
        }
        pausar();
    }
}

void Menu::crearReserva() {
    mostrarSubtitulo("Crear reserva");
    string idCliente = leerTexto("Identificacion del cliente: ");
    string codigoEspacio = leerTexto("Codigo del espacio: ");
    string fecha = leerTexto("Fecha (AAAA-MM-DD): ");
    string inicio = leerTexto("Hora de inicio (HH:MM): ");
    string fin = leerTexto("Hora de fin (HH:MM): ");
    try {
        Reserva *r = Fachada.crearReserva(idCliente, codigoEspacio, fecha, inicio, fin);
        mostrarExito("Reserva creada correctamente.");
        encabezadoReservas();
        filaReserva(r);
        lineaTabla(ANCHOS_RESERVAS, 8);
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::consultarReserva() {
    mostrarSubtitulo("Consultar reserva");
    string codigo = leerTexto("Codigo de la reserva: ");
    try {
        Reserva *r = Fachada.consultarReserva(codigo);
        cout << endl;
        encabezadoReservas();
        filaReserva(r);
        lineaTabla(ANCHOS_RESERVAS, 8);
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::cancelarReserva() {
    mostrarSubtitulo("Cancelar reserva");
    string codigo = leerTexto("Codigo de la reserva a cancelar: ");
    try {
        Reserva *r = Fachada.consultarReserva(codigo);
        cout << endl;
        encabezadoReservas();
        filaReserva(r);
        lineaTabla(ANCHOS_RESERVAS, 8);
        if (!confirmar("Confirma la cancelacion?")) {
            mostrarAdvertencia("Operacion cancelada.");
            return;
        }
        Fachada.cancelarReserva(codigo);
        mostrarExito("Reserva cancelada correctamente.");
    } catch (ExcepcionCentroDeportivo &e) {
        mostrarError(e.what());
    }
}

void Menu::listarReservas(bool soloActivas) {
    if (soloActivas) {
        mostrarSubtitulo("Reservas activas");
    } else {
        mostrarSubtitulo("Todas las reservas");
    }
    int mostradas = 0;
    IteradorReservas it = Fachada.iteradorReservas();
    while (it.hayMas()) {
        Reserva *r = it.siguiente();
        if (!soloActivas || r->estaActiva()) {
            if (mostradas == 0) {
                encabezadoReservas();
            }
            filaReserva(r);
            mostradas++;
        }
    }
    if (mostradas == 0) {
        mostrarAdvertencia("No hay reservas para mostrar.");
        return;
    }
    lineaTabla(ANCHOS_RESERVAS, 8);
    cout << colorNegrita() << "Total: " << mostradas << " reserva(s)." << colorReset() << endl;
}

void Menu::menuReportes() {
    int opcion = -1;
    while (opcion != 0 && cin) {
        mostrarTitulo("REPORTES");
        mostrarOpcion(1, "Total de reservas realizadas");
        mostrarOpcion(2, "Cliente con mayor cantidad de reservas");
        mostrarOpcion(3, "Espacio mas reservado");
        mostrarOpcion(4, "Reservas activas");
        mostrarOpcion(0, "Volver");
        mostrarPieMenu();
        opcion = leerEntero("Seleccione una opcion: ");
        if (opcion == 0 || !cin) {
            break;
        }
        mostrarSeparador();
        switch (opcion) {
            case 1: reporteTotalReservas(); break;
            case 2: reporteClienteConMasReservas(); break;
            case 3: reporteEspacioMasReservado(); break;
            case 4: listarReservas(true); break;
            default: mostrarError("Opcion invalida.");
        }
        pausar();
    }
}

void Menu::reporteTotalReservas() {
    int total = Fachada.totalReservas();
    int activas = Fachada.totalReservasActivas();
    mostrarSubtitulo("Total de reservas realizadas");
    mostrarDato("Total:", to_string(total));
    cout << "  " << colorNegrita() << left << setw(18) << "Activas:" << colorReset()
         << colorExito() << activas << colorReset() << endl;
    cout << "  " << colorNegrita() << left << setw(18) << "Canceladas:" << colorReset()
         << colorError() << total - activas << colorReset() << endl;
}

void Menu::reporteClienteConMasReservas() {
    mostrarSubtitulo("Cliente con mayor cantidad de reservas");
    int cantidad = 0;
    Cliente *c = Fachada.clienteConMasReservas(cantidad);
    if (c == NULL) {
        mostrarAdvertencia("Ningun cliente tiene reservas.");
        return;
    }
    encabezadoClientes();
    filaCliente(c);
    lineaTabla(ANCHOS_CLIENTES, 4);
    mostrarDato("Reservas:", to_string(cantidad));
}

void Menu::reporteEspacioMasReservado() {
    mostrarSubtitulo("Espacio mas reservado");
    int cantidad = 0;
    EspacioDeportivo *e = Fachada.espacioMasReservado(cantidad);
    if (e == NULL) {
        mostrarAdvertencia("Ningun espacio tiene reservas.");
        return;
    }
    encabezadoEspacios();
    filaEspacio(e);
    lineaTabla(ANCHOS_ESPACIOS, 6);
    mostrarDato("Reservas:", to_string(cantidad));
}
