#include "Torneo.h"
#include <iostream>
using namespace std;


Torneo::Torneo() {
    _idTorneo = 0;
    _nombre = "";
    _anio = 0;

}

Torneo::Torneo(int idTorneo, const char* nombre, int anio) {
    _idTorneo = idTorneo;
    strcpy(_nombre, nombre);
    _anio = anio;
}

void Torneo::setIdTorneo(int idTorneo) {
    _idTorneo = idTorneo;
}

void Torneo::setNombre(const string& nombre) {
    _nombre = nombre;
}

void Torneo::setAnio(int anio) { 
    _anio = anio;
}

int Torneo::getIdTorneo() {
    return _idTorneo;
}

string Torneo::getNombre() {
    return _nombre;
}

int Torneo::getAnio() {
    return _anio;
}

void Torneo::cargar() {
    cout << "ID Torneo: ";
    cin >> _idTorneo;
    cout << "Nombre: ";
    cin.ignore(); 
    cin.getline(_nombre, 30);
    cout << "Año: ";
    cin >> _anio;
}

void Torneo::mostrar() {
    cout << "ID Torneo: " << _idTorneo << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Año: " << _anio << endl;
}
