#include <iostream>
#include "Sistema.h"

using namespace std;

Sistema::Sistema() {
    contadorVuelos = 0;
    contadorUsuarios = 0;
    contadorReservaciones = 0;
}

void Sistema::mostrarMenu() {
    int opcion;

    do {
        cout << "----- Menu del Sistema de Reservaciones -----" << endl;
        cout << "1. Agregar Vuelo" << endl;
        cout << "2. Mostrar Vuelos" << endl;
        cout << "3. Agregar Usuario" << endl;
        cout << "4. Mostrar Usuarios" << endl;
        cout << "5. Crear Reservacion" << endl;
        cout << "6. Mostrar Reservaciones" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarVuelo();
                break;
            case 2:
                mostrarVuelos();
                break;
            case 3:
                agregarUsuario();
                break;
            case 4:
                mostrarUsuarios();
                break;
            case 5:
                crearReservacion();
                break;
            case 6:
                mostrarReservaciones();
                break;
            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);
}
//vuelos
void Sistema::agregarVuelo() {
    if (contadorVuelos >= 10) {
        cout << "No se pueden agregar mas vuelos." << endl;
        return;
    }
    
    int id, kilometros;
    string nombre;
    double precio;

    cout << "Ingrese ID del vuelo: ";
    cin >> id;
    cout << "Ingrese nombre del vuelo: ";
    cin >> nombre;
    cout << "Ingrese precio del vuelo: ";
    cin >> precio;
    cout << "Ingrese kilometros del vuelo: ";
    cin >> kilometros;

    vuelo[contadorVuelos] = Vuelo(id, nombre, precio, kilometros);
    contadorVuelos++;

    cout << "Vuelo agregado exitosamente." << endl;
}

void Sistema::mostrarVuelos() {
    cout << "-----Lista de Vuelos-----" << endl;
    for (int i = 0; i < contadorVuelos; i++) {
        cout << "ID: " << vuelo[i].getId() 
            << ", Nombre: " << vuelo[i].getNombre() 
            << ", Precio: " << vuelo[i].getPrecio() 
            << ", Kilometros: " << vuelo[i].getKilometros() << endl;
    }
}

//usuarios

void Sistema::agregarUsuario() {
    if (contadorUsuarios >= 10) {
        cout << "No se pueden agregar mas usuarios." << endl;
        return;
    }
    
    int id;
    string nombre;

    cout << "Ingrese ID del usuario: ";
    cin >> id;
    cout << "Ingrese nombre del usuario: ";
    cin >> nombre;

    usuarios[contadorUsuarios] = Usuario(id, nombre);
    contadorUsuarios++;

    cout << "Usuario agregado exitosamente." << endl;
}

void Sistema::mostrarUsuarios() {
    cout << "-----Lista de Usuarios-----" << endl;
    for (int i = 0; i < contadorUsuarios; i++) {
        cout << "ID: " << usuarios[i].getId() 
            << ", Nombre: " << usuarios[i].getNombre() 
            << ", Km Acumulados: " << usuarios[i].getKmAcumulados() << endl;
    }
}

//reservaciones
void Sistema::crearReservacion() {
    if (contadorReservaciones >= 10) {
        cout << "No se pueden crear mas reservaciones." << endl;
        return;
    }
    int idUsuario, idVuelo;
    cout << "Ingrese ID del usuario: ";
    cin >> idUsuario;
    cout << "Ingrese ID del vuelo: ";
    cin >> idVuelo;

    //búsqueda del usuario
    int indiceUsuario = -1;
    for (int i = 0; i < contadorUsuarios; i++) {
        if (usuarios[i].getId() == idUsuario) {
            indiceUsuario = i;
            break;
        }
    }
    //búsqueda del vuelo
    int indiceVuelo = -1;
    for (int i = 0; i < contadorVuelos; i++) {
        if (vuelo[i].getId() == idVuelo) {
            indiceVuelo = i;
            break;
        }
    }

//caso de no encontrar usuario o vuelo, arrojar error
    if (indiceUsuario == -1 || indiceVuelo == -1) {
        cout << "Usuario o vuelo no encontrado." << endl;
        return;
    }

    double precioFinal = vuelo[indiceVuelo].getPrecio();

    //descuentos :D

    if(usuarios[indiceUsuario].getKmAcumulados() > 50000) {
        precioFinal *= 0.6; //40% de descuento
        cout << "Se aplico un descuento del 40% por tener mas de 50,000 km acumulados." << endl;
    }

    //acumular los km

    usuarios[indiceUsuario].agregarKilometros(vuelo[indiceVuelo].getKilometros());

    reservaciones[contadorReservaciones] = Reservacion(idUsuario, idVuelo, precioFinal);
    contadorReservaciones++;

    cout << "Reservacion creada exitosamente. Precio final: " << precioFinal << endl;
}

void Sistema::mostrarReservaciones() {
    cout << "-----Lista de Reservaciones-----" << endl;
    for (int i = 0; i < contadorReservaciones; i++) {
        cout << "ID Usuario: " << reservaciones[i].getIdUsuario() 
            << ", ID Vuelo: " << reservaciones[i].getIdVuelo() 
            << ", Precio Final: " << reservaciones[i].getPrecioFinal() << endl;
    }
}