#include "Sistema/FachadaCentroDeportivo.h"
#include "Espacio/Fabrica/FabricaEspacio.h"
#include "Excepciones/ClienteNoEncontrado.h"
#include "Excepciones/ClienteDuplicado.h"
#include "Excepciones/EspacioNoEncontrado.h"
#include "Excepciones/EspacioDuplicado.h"
#include "Excepciones/ReservaNoEncontrada.h"
#include "Excepciones/ConflictoHorario.h"
#include "Excepciones/DatoInvalido.h"
#include <sstream>
#include <cstdlib>

FachadaCentroDeportivo::FachadaCentroDeportivo() {
    Admin = AdministradorSistema::obtenerInstancia();
}

void FachadaCentroDeportivo::validarTexto(string valor, string nombreCampo) {
    if (valor.empty()) {
        throw DatoInvalido("El campo " + nombreCampo + " no puede estar vacio.");
    }
    if (valor.find(',') != string::npos) {
        throw DatoInvalido("El campo " + nombreCampo + " no puede contener comas.");
    }
}

void FachadaCentroDeportivo::validarHorario(string fecha, string horaInicio, string horaFin) {
    if (!Reserva::fechaValida(fecha)) {
        throw DatoInvalido("Fecha invalida. Use el formato AAAA-MM-DD.");
    }
    if (!Reserva::horaValida(horaInicio) || !Reserva::horaValida(horaFin)) {
        throw DatoInvalido("Hora invalida. Use el formato HH:MM (00:00 a 23:59).");
    }
    if (horaInicio >= horaFin) {
        throw DatoInvalido("La hora de inicio debe ser anterior a la hora de fin.");
    }
}

string FachadaCentroDeportivo::generarCodigoReserva() {
    int mayor = 0;
    IteradorReservas it = Admin->getReservas()->crearIterador();
    while (it.hayMas()) {
        string codigo = it.siguiente()->getCodigo();
        int numero = atoi(codigo.substr(1).c_str());
        if (numero > mayor) {
            mayor = numero;
        }
    }
    stringstream ss;
    ss << "R";
    if (mayor + 1 < 100) {
        ss << "0";
    }
    if (mayor + 1 < 10) {
        ss << "0";
    }
    ss << mayor + 1;
    return ss.str();
}

void FachadaCentroDeportivo::cargarDatos(int &clientes, int &espacios, int &reservas) {
    Admin->cargarDatos(clientes, espacios, reservas);
}

void FachadaCentroDeportivo::guardarDatos() {
    Admin->guardarDatos();
}

void FachadaCentroDeportivo::registrarCliente(string id, string nombre, string telefono, string correo) {
    validarTexto(id, "identificacion");
    validarTexto(nombre, "nombre");
    validarTexto(telefono, "telefono");
    validarTexto(correo, "correo");
    if (correo.find('@') == string::npos) {
        throw DatoInvalido("El correo debe contener '@'.");
    }
    if (Admin->getClientes()->buscarPorId(id) != NULL) {
        throw ClienteDuplicado(id);
    }
    Admin->getClientes()->IngresaCliente(new Cliente(id, nombre, telefono, correo));
}

void FachadaCentroDeportivo::modificarCliente(string id, string nombre, string telefono, string correo) {
    Cliente *cliente = buscarCliente(id);
    validarTexto(nombre, "nombre");
    validarTexto(telefono, "telefono");
    validarTexto(correo, "correo");
    if (correo.find('@') == string::npos) {
        throw DatoInvalido("El correo debe contener '@'.");
    }
    cliente->setNombre(nombre);
    cliente->setTelefono(telefono);
    cliente->setCorreo(correo);
}

Cliente* FachadaCentroDeportivo::buscarCliente(string id) {
    Cliente *cliente = Admin->getClientes()->buscarPorId(id);
    if (cliente == NULL) {
        throw ClienteNoEncontrado(id);
    }
    return cliente;
}

IteradorClientes FachadaCentroDeportivo::iteradorClientes() {
    return Admin->getClientes()->crearIterador();
}

void FachadaCentroDeportivo::registrarEspacio(string tipo, string codigo, string nombre,
                                              int capacidad, double precioHora) {
    validarTexto(codigo, "codigo");
    validarTexto(nombre, "nombre");
    if (Admin->getEspacios()->buscarPorCodigo(codigo) != NULL) {
        throw EspacioDuplicado(codigo);
    }
    FabricaEspacio *fabrica = FabricaEspacio::obtenerFabrica(tipo);
    try {
        EspacioDeportivo *espacio = fabrica->fabricar(codigo, nombre, capacidad, precioHora);
        Admin->getEspacios()->IngresaEspacio(espacio);
    } catch (...) {
        delete fabrica;
        throw;
    }
    delete fabrica;
}

EspacioDeportivo* FachadaCentroDeportivo::buscarEspacio(string codigo) {
    EspacioDeportivo *espacio = Admin->getEspacios()->buscarPorCodigo(codigo);
    if (espacio == NULL) {
        throw EspacioNoEncontrado(codigo);
    }
    return espacio;
}

bool FachadaCentroDeportivo::estaOcupado(string codigoEspacio) {
    return Admin->getReservas()->tieneActivaEnEspacio(codigoEspacio);
}

bool FachadaCentroDeportivo::consultarDisponibilidad(string codigoEspacio, string fecha,
                                                     string horaInicio, string horaFin) {
    buscarEspacio(codigoEspacio);
    validarHorario(fecha, horaInicio, horaFin);
    IteradorReservas it = Admin->getReservas()->crearIterador();
    while (it.hayMas()) {
        Reserva *r = it.siguiente();
        if (r->estaActiva() && r->getCodigoEspacio() == codigoEspacio
            && r->seTraslapaCon(fecha, horaInicio, horaFin)) {
            return false;
        }
    }
    return true;
}

IteradorEspacios FachadaCentroDeportivo::iteradorEspacios() {
    return Admin->getEspacios()->crearIterador();
}


Reserva* FachadaCentroDeportivo::crearReserva(string idCliente, string codigoEspacio, string fecha,
                                              string horaInicio, string horaFin) {
    buscarCliente(idCliente);
    buscarEspacio(codigoEspacio);
    validarHorario(fecha, horaInicio, horaFin);

    IteradorReservas it = Admin->getReservas()->crearIterador();
    while (it.hayMas()) {
        Reserva *r = it.siguiente();
        if (r->estaActiva() && r->getCodigoEspacio() == codigoEspacio
            && r->seTraslapaCon(fecha, horaInicio, horaFin)) {
            throw ConflictoHorario("el espacio " + codigoEspacio + " ya tiene la reserva "
                                   + r->getCodigo() + " el " + r->getFecha() + " de "
                                   + r->getHoraInicio() + " a " + r->getHoraFin() + ".");
        }
    }

    Reserva *nueva = new Reserva(generarCodigoReserva(), idCliente, codigoEspacio,
                                 fecha, horaInicio, horaFin, true);
    Admin->getReservas()->IngresaReserva(nueva);
    return nueva;
}

Reserva* FachadaCentroDeportivo::consultarReserva(string codigo) {
    Reserva *reserva = Admin->getReservas()->buscarPorCodigo(codigo);
    if (reserva == NULL) {
        throw ReservaNoEncontrada(codigo);
    }
    return reserva;
}

void FachadaCentroDeportivo::cancelarReserva(string codigo) {
    Reserva *reserva = consultarReserva(codigo);
    if (!reserva->estaActiva()) {
        throw DatoInvalido("La reserva " + codigo + " ya estaba cancelada.");
    }
    reserva->cancelar();
}

double FachadaCentroDeportivo::calcularCostoReserva(Reserva *reserva) {
    EspacioDeportivo *espacio = Admin->getEspacios()->buscarPorCodigo(reserva->getCodigoEspacio());
    if (espacio == NULL) {
        return 0;
    }
    return espacio->calcularCosto(reserva->duracionHoras());
}

IteradorReservas FachadaCentroDeportivo::iteradorReservas() {
    return Admin->getReservas()->crearIterador();
}

int FachadaCentroDeportivo::totalReservas() {
    return Admin->getReservas()->getCantidad();
}

int FachadaCentroDeportivo::totalReservasActivas() {
    return Admin->getReservas()->contarActivas();
}

Cliente* FachadaCentroDeportivo::clienteConMasReservas(int &cantidad) {
    Cliente *mejor = nullptr;
    cantidad = 0;
    IteradorClientes it = Admin->getClientes()->crearIterador();
    while (it.hayMas()) {
        Cliente *c = it.siguiente();
        int total = Admin->getReservas()->contarPorCliente(c->getId());
        if (total > cantidad) {
            cantidad = total;
            mejor = c;
        }
    }
    return mejor;
}

EspacioDeportivo* FachadaCentroDeportivo::espacioMasReservado(int &cantidad) {
    EspacioDeportivo *mejor = nullptr;
    cantidad = 0;
    IteradorEspacios it = Admin->getEspacios()->crearIterador();
    while (it.hayMas()) {
        EspacioDeportivo *e = it.siguiente();
        int total = Admin->getReservas()->contarPorEspacio(e->getCodigo());
        if (total > cantidad) {
            cantidad = total;
            mejor = e;
        }
    }
    return mejor;
}
