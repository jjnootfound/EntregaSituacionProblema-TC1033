#ifndef RESERVACION_H
#define RESERVACION_H

class Reservacion { 
private:
    int idUsuario;
    int idVuelo;
    double precioFinal;

public:
    Reservacion();
    Reservacion(int idUsuario, int idVuelo, double precioFinal);

    int getIdUsuario();
    int getIdVuelo();   
    double getPrecioFinal();  

    void setIdUsuario(int idUsuario);
    void setIdVuelo(int idVuelo);
    void setPrecioFinal(double precioFinal);
};

#endif