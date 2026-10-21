#include "Archivo/Archivo.h"
#include "Espacio/Fabrica/FabricaEspacio.h"
#include "Excepciones/ErrorArchivo.h"
#include "Excepciones/DatoInvalido.h"
#include <fstream>
#include <cstdlib>
#include <iomanip>

string Archivo::siguienteCampo(string &linea) {
    size_t pos = linea.find(',');
    string campo;
    if (pos == string::npos) {
        campo = linea;
        linea = "";
    } else {
        campo = linea.substr(0, pos);
        linea = linea.substr(pos + 1);
    }
    return campo;
}

string Archivo::quitarFinDeLinea(string linea) {
    if (!linea.empty() && linea[linea.length() - 1] == '\r') {
        linea = linea.substr(0, linea.length() - 1);
    }
    return linea;
}

int Archivo::cargarClientes(ListaClientes *lista, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        throw ErrorArchivo(nombreArchivo);
    }
    int cargados = 0;
    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        linea = quitarFinDeLinea(linea);
        if (linea.empty()) {
            continue;
        }
        string id = siguienteCampo(linea);
        string nombre = siguienteCampo(linea);
        string telefono = siguienteCampo(linea);
        string correo = siguienteCampo(linea);

        if (id.empty() || nombre.empty() || lista->buscarPorId(id) != nullptr) {
            continue;
        }
        lista->IngresaCliente(new Cliente(id, nombre, telefono, correo));
        cargados++;
    }
    archivo.close();
    return cargados;
}

void Archivo::guardarClientes(ListaClientes *lista, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        throw ErrorArchivo(nombreArchivo);
    }
    archivo << "id,nombre,telefono,correo" << endl;
    IteradorClientes it = lista->crearIterador();
    while (it.hayMas()) {
        Cliente *c = it.siguiente();
        archivo << c->getId() << "," << c->getNombre() << ","
                << c->getTelefono() << "," << c->getCorreo() << endl;
    }
    archivo.close();
}

int Archivo::cargarEspacios(ListaEspacios *lista, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        throw ErrorArchivo(nombreArchivo);
    }
    int cargados = 0;
    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        linea = quitarFinDeLinea(linea);
        if (linea.empty()) {
            continue;
        }
        string codigo = siguienteCampo(linea);
        string tipo = siguienteCampo(linea);
        string nombre = siguienteCampo(linea);
        int capacidad = atoi(siguienteCampo(linea).c_str());
        double precioHora = atof(siguienteCampo(linea).c_str());

        if (lista->buscarPorCodigo(codigo) != nullptr) {
            continue;
        }
        FabricaEspacio *fabrica = nullptr;
        try {
            fabrica = FabricaEspacio::obtenerFabrica(tipo);
            lista->IngresaEspacio(fabrica->fabricar(codigo, nombre, capacidad, precioHora));
            cargados++;
        } catch (DatoInvalido &) {
        }
        delete fabrica;
    }
    archivo.close();
    return cargados;
}

void Archivo::guardarEspacios(ListaEspacios *lista, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        throw ErrorArchivo(nombreArchivo);
    }
    archivo << fixed << setprecision(2);
    archivo << "codigo,tipo,nombre,capacidad,precioHora" << endl;
    IteradorEspacios it = lista->crearIterador();
    while (it.hayMas()) {
        EspacioDeportivo *e = it.siguiente();
        archivo << e->getCodigo() << "," << e->obtenerTipo() << "," << e->getNombre() << ","
                << e->getCapacidad() << "," << e->getPrecioHora() << endl;
    }
    archivo.close();
}

int Archivo::cargarReservas(ListaReservas *lista, string nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        throw ErrorArchivo(nombreArchivo);
    }
    int cargados = 0;
    string linea;
    getline(archivo, linea);
    while (getline(archivo, linea)) {
        linea = quitarFinDeLinea(linea);
        if (linea.empty()) {
            continue;
        }
        string codigo = siguienteCampo(linea);
        string idCliente = siguienteCampo(linea);
        string codigoEspacio = siguienteCampo(linea);
        string fecha = siguienteCampo(linea);
        string horaInicio = siguienteCampo(linea);
        string horaFin = siguienteCampo(linea);
        string estado = siguienteCampo(linea);

        if (codigo.empty() || lista->buscarPorCodigo(codigo) != nullptr) {
            continue;
        }
        if (!Reserva::fechaValida(fecha) || !Reserva::horaValida(horaInicio)
            || !Reserva::horaValida(horaFin) || horaInicio >= horaFin) {
            continue;
        }
        if (estado != "Activa" && estado != "Cancelada") {
            continue;
        }
        lista->IngresaReserva(new Reserva(codigo, idCliente, codigoEspacio, fecha,
                                          horaInicio, horaFin, estado == "Activa"));
        cargados++;
    }
    archivo.close();
    return cargados;
}

void Archivo::guardarReservas(ListaReservas *lista, string nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        throw ErrorArchivo(nombreArchivo);
    }
    archivo << "codigo,idCliente,codigoEspacio,fecha,horaInicio,horaFin,estado" << endl;
    IteradorReservas it = lista->crearIterador();
    while (it.hayMas()) {
        Reserva *r = it.siguiente();
        archivo << r->getCodigo() << "," << r->getIdCliente() << "," << r->getCodigoEspacio() << ","
                << r->getFecha() << "," << r->getHoraInicio() << "," << r->getHoraFin() << ","
                << r->getEstadoTexto() << endl;
    }
    archivo.close();
}
