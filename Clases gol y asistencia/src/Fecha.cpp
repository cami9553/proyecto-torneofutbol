#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(){
        _dia = 0;
        _mes = 0;
        _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio){
        _dia = dia;
        _mes = mes;
        _anio = anio;
}

// Getters
int Fecha::getDia() {
    return _dia;
}

int Fecha::getMes() {
    return _mes;
}

int Fecha::getAnio() {
    return _anio;
}

// Setters
void Fecha::setDia(int d) {
    _dia = d;
}

void Fecha::setMes(int m) {
    _mes = m;
}

void Fecha::setAnio(int a) {
    _anio = a;
}

std::string Fecha::toString(){
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

//Otros metodos
void Fecha::cargar(){
    cout << "Dia: " << endl;
    cin >> _dia;
    cout << "Mes: " << endl;
    cin >> _mes;
    cout << "Anio: " << endl;
    cin >> _anio;

}
