#ifndef VUELO_H
#define VUELO_H

#include <string>
using namespace std;


class Vuelo {
private:
    int id;  //número de vuelo
    string nombre;
    double precio;
    int kilometros;

public:
    Vuelo();
    Vuelo(int id, string nombre, double precio, int kilometros);
    ~Vuelo();

    int getId();
    string getNombre();
    double getPrecio();
    int getKilometros();

    void setId(int id);
    void setNombre(string nombre);
    void setPrecio(double precio);
    void setKilometros(int kilometros);
};

#endif
