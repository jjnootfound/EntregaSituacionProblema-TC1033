#include "Reservacion.h"

Reservacion::Reservacion() {
    idUsuario = 0;
    idVuelo = 0;
    precioFinal = 0.0;
}

Reservacion::Reservacion(int idUsuario, int idVuelo, double precioFinal) {
    this->idUsuario = idUsuario;
    this->idVuelo = idVuelo;
    this->precioFinal = precioFinal;
}

int Reservacion::getIdUsuario() {
    return idUsuario;
}

int Reservacion::getIdVuelo() {
    return idVuelo;
}

double Reservacion::getPrecioFinal() {
    return precioFinal;
}

void Reservacion::setIdUsuario(int idUsuario) {
    this->idUsuario = idUsuario;
}

void Reservacion::setIdVuelo(int idVuelo) {
    this->idVuelo = idVuelo;
}

void Reservacion::setPrecioFinal(double precioFinal) {
    this->precioFinal = precioFinal;
}