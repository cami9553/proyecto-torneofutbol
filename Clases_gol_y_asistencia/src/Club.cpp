#include <cstring>
#include <iostream>
#include "Club.h"
#include <limits>
#include "Validaciones.h"


using namespace std;
int Club::_ultimoId = 0;

Club::Club() {
    _idClub = 0;
    strcpy(_nombre, "");
    strcpy(_presidente, "");
    strcpy(_ciudad, "");
}

void Club::setUltimoId(int ultimoId) {_ultimoId = ultimoId;}
int Club::getUltimoId() {return _ultimoId;}
void Club::generarNuevoId() {_idClub = ++_ultimoId;}

void Club::setIdClub(int idClub){ _idClub = idClub;}
void Club::setNombre(std::string nombre){strcpy(_nombre, nombre.c_str());}
void Club::setPresidente(std::string presidente){strcpy(_presidente, presidente.c_str());}
void Club::setCiudad(std::string ciudad){strcpy(_ciudad, ciudad.c_str());}

int Club::getIdClub(){ return _idClub;}
const char *Club::getNombre(){ return _nombre;}
const char *Club::getPresidente(){ return _presidente;}
const char *Club::getCiudad(){ return _ciudad;}


bool Club::cargar()
{
    cout << "ID Club: " << _idClub << endl;

    if (!leerNombreApellido(_nombre, 30, "Nombre del club"))
        return false;

    if (!leerNombreApellido(_presidente, 30, "Presidente"))
        return false;

    if (!leerNombreApellido(_ciudad, 30, "Ciudad"))
        return false;

    return true; // ← solo si todo salió bien
}


void Club::mostrar(){
    cout << "ID Club: " << _idClub << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Presidente: " << _presidente << endl;
    cout << "Ciudad: " << _ciudad << endl;
}
