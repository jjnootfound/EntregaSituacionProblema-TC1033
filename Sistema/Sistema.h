#ifndef SISTEMA_H
#define SISTEMA_H

#include "../Vuelo/Vuelo.h"
#include "../Usuario/Usuario.h"
#include "../Reservacion/Reservacion.h"


class Sistema {
private: 
    Vuelo vuelo[10];
    Usuario usuarios[10];
    Reservacion reservaciones[10];

    int contadorVuelos;
    int contadorUsuarios;
    int contadorReservaciones;

public:
    Sistema();
    
    void mostrarMenu();

    void agregarVuelo();
    void mostrarVuelos();

    void agregarUsuario();
    void mostrarUsuarios();

    void crearReservacion();
    void mostrarReservaciones();
};

#endif