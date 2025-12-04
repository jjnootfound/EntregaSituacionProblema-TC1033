#include "Vuelo.h"

Vuelo::Vuelo() {
    id = 0;
    nombre = "";
    precio = 0;
    kilometros = 0;
}

Vuelo::Vuelo(int id, string nombre, double precio, int kilometros) {
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
    this->kilometros = kilometros;
}

//métodos: getters y setters
int Vuelo::getId() { 
    return id; 
    }

string Vuelo::getNombre() {
    return nombre; 
    }

double Vuelo::getPrecio() {
    return precio; 
    }

int Vuelo::getKilometros() {
    return kilometros; 
    }

void Vuelo::setId(int id) {
    this->id = id; 
    }

void Vuelo::setNombre(string nombre) { 
    this->nombre = nombre; 
    }

void Vuelo::setPrecio(double precio) { 
    this->precio = precio; 
    }

void Vuelo::setKilometros(int kilometros) { 
    this->kilometros = kilometros; 
    }