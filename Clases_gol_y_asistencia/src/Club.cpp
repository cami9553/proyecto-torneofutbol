#include <cstring>
#include <iostream>
#include "Club.h"
#include <limits>


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


void Club::cargar()
{
    cout << "ID del nuevo Club: " << _idClub << endl;

    cout << "Ingrese nombre del club:";
    cin.getline(_nombre, 30);

    cout << "Ingrese Presidente:";
    cin.getline(_presidente, 30);

    cout << "Ingrese Ciudad:";
    cin.getline(_ciudad, 30);
}

void Club::mostrar(){
    cout << "ID Club: " << _idClub << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Presidente: " << _presidente << endl;
    cout << "Ciudad: " << _ciudad << endl;
}
