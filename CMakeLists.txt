cmake_minimum_required(VERSION 3.16)
project(Proyecto)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Proyecto
        main.cpp

        Cliente/Cliente.h Cliente/Cliente.cpp
        Cliente/NodoCliente.h Cliente/NodoCliente.cpp
        Cliente/ListaClientes.h Cliente/ListaClientes.cpp
        Cliente/IteradorClientes.h Cliente/IteradorClientes.cpp

        Espacio/EspacioDeportivo.h Espacio/EspacioDeportivo.cpp
        Espacio/CanchaFutbol.h Espacio/CanchaFutbol.cpp
        Espacio/CanchaBaloncesto.h Espacio/CanchaBaloncesto.cpp
        Espacio/CanchaTenis.h Espacio/CanchaTenis.cpp
        Espacio/Piscina.h Espacio/Piscina.cpp
        Espacio/SalaFuncional.h Espacio/SalaFuncional.cpp

        Espacio/NodoEspacio.h Espacio/NodoEspacio.cpp
        Espacio/ListaEspacios.h Espacio/ListaEspacios.cpp
        Espacio/IteradorEspacios.h Espacio/IteradorEspacios.cpp

        Espacio/Fabrica/FabricaEspacio.h Espacio/Fabrica/FabricaEspacio.cpp
        Espacio/Fabrica/FabricaCanchaFutbol.h Espacio/Fabrica/FabricaCanchaFutbol.cpp
        Espacio/Fabrica/FabricaCanchaBaloncesto.h Espacio/Fabrica/FabricaCanchaBaloncesto.cpp
        Espacio/Fabrica/FabricaCanchaTenis.h Espacio/Fabrica/FabricaCanchaTenis.cpp
        Espacio/Fabrica/FabricaPiscina.h Espacio/Fabrica/FabricaPiscina.cpp
        Espacio/Fabrica/FabricaSalaFuncional.h Espacio/Fabrica/FabricaSalaFuncional.cpp

        Reserva/Reserva.h Reserva/Reserva.cpp
        Reserva/NodoReserva.h Reserva/NodoReserva.cpp
        Reserva/ListaReservas.h Reserva/ListaReservas.cpp
        Reserva/IteradorReservas.h Reserva/IteradorReservas.cpp

        Archivo/Archivo.h Archivo/Archivo.cpp

        Excepciones/ExcepcionCentroDeportivo.h Excepciones/ExcepcionCentroDeportivo.cpp
        Excepciones/ClienteNoEncontrado.h Excepciones/ClienteNoEncontrado.cpp
        Excepciones/ClienteDuplicado.h Excepciones/ClienteDuplicado.cpp
        Excepciones/EspacioNoEncontrado.h Excepciones/EspacioNoEncontrado.cpp
        Excepciones/EspacioDuplicado.h Excepciones/EspacioDuplicado.cpp
        Excepciones/ReservaNoEncontrada.h Excepciones/ReservaNoEncontrada.cpp
        Excepciones/ConflictoHorario.h Excepciones/ConflictoHorario.cpp
        Excepciones/DatoInvalido.h Excepciones/DatoInvalido.cpp
        Excepciones/ErrorArchivo.h Excepciones/ErrorArchivo.cpp

        Sistema/AdministradorSistema.h Sistema/AdministradorSistema.cpp
        Sistema/FachadaCentroDeportivo.h Sistema/FachadaCentroDeportivo.cpp

        Menu/Menu.h Menu/Menu.cpp
)

# Permite escribir los #include con la ruta desde la raiz del proyecto,
# por ejemplo #include "Cliente/ListaClientes.h".
target_include_directories(Proyecto PRIVATE ${CMAKE_SOURCE_DIR})

# Copia los CSV de datos/ a <carpeta del build>/datos/ para que el programa
# los encuentre con la ruta "datos/..." al ejecutarse desde CLion.
# Ojo: al reconfigurar CMake, si el CSV original cambio, la copia del build
# se reemplaza por el original.
foreach(DATA_FILE clientes.csv espacios.csv reservas.csv)
    configure_file(${CMAKE_SOURCE_DIR}/datos/${DATA_FILE} ${CMAKE_CURRENT_BINARY_DIR}/datos/${DATA_FILE} COPYONLY)
endforeach()
