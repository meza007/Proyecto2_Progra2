#include "Excepciones/ErrorArchivo.h"

ErrorArchivo::ErrorArchivo(string nombreArchivo)
    : ExcepcionCentroDeportivo("No se pudo abrir el archivo " + nombreArchivo + ".") {
}
