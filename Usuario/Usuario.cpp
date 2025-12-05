#include "Usuario.h"

Usuario::Usuario() {
    id = 0;
    nombre = "";
    kmAcumulados = 0;
}

Usuario::Usuario(int id, string nombre, int kmAcumulados) {
    this->id = id;
    this->nombre = nombre;
    this->kmAcumulados = kmAcumulados;
}

int Usuario::getId() {
    return id;
}
string Usuario::getNombre() {
    return nombre;
}

int Usuario::getKmAcumulados() {
    return kmAcumulados;
}

void Usuario::setId(int id) {
    this->id = id;
}

void Usuario::setNombre(string nombre) {
    this->nombre = nombre;
}

void Usuario::setKmAcumulados(int kmAcumulados) {
    this->kmAcumulados = kmAcumulados;
}

void Usuario::agregarKilometros(int km) {
    kmAcumulados += km;
}