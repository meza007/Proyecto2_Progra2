#include "Excepciones/ClienteNoEncontrado.h"

ClienteNoEncontrado::ClienteNoEncontrado(string id)
    : ExcepcionCentroDeportivo("No existe un cliente con identificacion " + id + ".") {
}
