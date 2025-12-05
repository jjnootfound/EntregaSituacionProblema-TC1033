#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
private:
    int id;
    string nombre;
    int kmAcumulados;

public:
    Usuario ();
    Usuario (int id, string nombre);
    

    int getId();
    string getNombre();
    int getKmAcumulados();

    void setId(int id);
    void setNombre(string nombre);
    void setKmAcumulados(int kmAcumulados);

    void agregarKilometros(int km);
};

#endif