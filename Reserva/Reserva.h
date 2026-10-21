#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
using namespace std;

class Reserva {
private:
    string Codigo;
    string IdCliente;
    string CodigoEspacio;
    string Fecha;
    string HoraInicio;
    string HoraFin;
    bool Activa;

    static int minutosDelDia(string hora);

public:
    Reserva(string codigo, string idCliente, string codigoEspacio,string fecha, string horaInicio, string horaFin, bool activa);

    string getCodigo();
    string getIdCliente();
    string getCodigoEspacio();
    string getFecha();
    string getHoraInicio();
    string getHoraFin();

    bool estaActiva();
    void cancelar();
    string getEstadoTexto();

    double duracionHoras();
    bool seTraslapaCon(string fecha, string horaInicio, string horaFin);

    static bool fechaValida(string fecha);
    static bool horaValida(string hora);

    string toString();
};

#endif
