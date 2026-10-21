#include "Excepciones/ClienteDuplicado.h"

ClienteDuplicado::ClienteDuplicado(string id)
    : ExcepcionCentroDeportivo("Ya existe un cliente con identificacion " + id + ".") {
}
