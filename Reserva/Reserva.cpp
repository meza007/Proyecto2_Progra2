#include "Reserva/Reserva.h"
#include <sstream>
#include <cstdlib>
#include <cctype>

Reserva::Reserva(string codigo, string idCliente, string codigoEspacio,
                 string fecha, string horaInicio, string horaFin, bool activa) {
    Codigo = codigo;
    IdCliente = idCliente;
    CodigoEspacio = codigoEspacio;
    Fecha = fecha;
    HoraInicio = horaInicio;
    HoraFin = horaFin;
    Activa = activa;
}

string Reserva::getCodigo() {
    return Codigo;
}

string Reserva::getIdCliente() {
    return IdCliente;
}

string Reserva::getCodigoEspacio() {
    return CodigoEspacio;
}

string Reserva::getFecha() {
    return Fecha;
}

string Reserva::getHoraInicio() {
    return HoraInicio;
}

string Reserva::getHoraFin() {
    return HoraFin;
}

bool Reserva::estaActiva() {
    return Activa;
}

void Reserva::cancelar() {
    Activa = false;
}

string Reserva::getEstadoTexto() {
    if (Activa) {
        return "Activa";
    }
    return "Cancelada";
}

int Reserva::minutosDelDia(string hora) {
    int horas = atoi(hora.substr(0, 2).c_str());
    int minutos = atoi(hora.substr(3, 2).c_str());
    return horas * 60 + minutos;
}

double Reserva::duracionHoras() {
    return (minutosDelDia(HoraFin) - minutosDelDia(HoraInicio)) / 60.0;
}

bool Reserva::seTraslapaCon(string fecha, string horaInicio, string horaFin) {
    if (fecha != Fecha) {
        return false;
    }
    return horaInicio < HoraFin && HoraInicio < horaFin;
}

bool Reserva::fechaValida(string fecha) {
    if (fecha.length() != 10 || fecha[4] != '-' || fecha[7] != '-') {
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !isdigit((unsigned char) fecha[i])) {
            return false;
        }
    }
    int anio = atoi(fecha.substr(0, 4).c_str());
    int mes = atoi(fecha.substr(5, 2).c_str());
    int dia = atoi(fecha.substr(8, 2).c_str());
    if (mes < 1 || mes > 12 || dia < 1) {
        return false;
    }
    int diasMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
    if (bisiesto) {
        diasMes[1] = 29;
    }
    return dia <= diasMes[mes - 1];
}

bool Reserva::horaValida(string hora) {
    if (hora.length() != 5 || hora[2] != ':') {
        return false;
    }
    if (!isdigit((unsigned char) hora[0]) || !isdigit((unsigned char) hora[1])
        || !isdigit((unsigned char) hora[3]) || !isdigit((unsigned char) hora[4])) {
        return false;
    }
    int horas = atoi(hora.substr(0, 2).c_str());
    int minutos = atoi(hora.substr(3, 2).c_str());
    return horas <= 23 && minutos <= 59;
}

string Reserva::toString() {
    stringstream ss;
    ss << "Codigo: " << Codigo
       << " | Cliente: " << IdCliente
       << " | Espacio: " << CodigoEspacio
       << " | Fecha: " << Fecha
       << " | Horario: " << HoraInicio << "-" << HoraFin
       << " | Estado: " << getEstadoTexto();
    return ss.str();
}
