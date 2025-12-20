#include "Persona.h"
#include "Validaciones.h"
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
int Persona::_ultimoId = 0;

Persona::Persona()
{
    _idPersona = 0;
    _dni = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_telefono, "");
    strcpy(_email,"");
    Fecha _fechaNacimiento;

}

Persona::Persona(int dni, const char* apellido, const char* nombre, const char* telefono, const char* email, Fecha fechaNacimiento) {
    _idPersona = 0;
    _dni = dni;
    strcpy(_apellido, apellido);
    strcpy(_nombre, nombre);
    strcpy(_telefono, telefono);
    strcpy(_email, email);
    _fechaNacimiento = fechaNacimiento;
}

int Persona::getUltimoId(){return _ultimoId;}
void Persona::setUltimoId(int ultimoId) {_ultimoId = ultimoId;}
void Persona::generarNuevoId() {_idPersona = ++_ultimoId;}

//Setters
void Persona::setDni(int dni){
	_dni = dni;
}

void Persona::setApellido(std::string apellido){
	strcpy(_apellido, apellido.c_str());
}

void Persona::setNombre(std::string nombre){
	strcpy(_nombre, nombre.c_str());
}

void Persona::setTelefono(std::string telefono){
	strcpy(_telefono, telefono.c_str());
}

void Persona::setEmail(std::string email){
	strcpy(_email, email.c_str());
}

void Persona::setFechaNacimiento(Fecha f) {
    _fechaNacimiento = f;
}

//Getters

int Persona::getId(){
    return _idPersona;
}

int Persona::getDni(){
	return _dni;
}

const char *Persona::getApellido(){
	return _apellido;
}

const char *Persona::getNombre(){
	return _nombre;
}

const char *Persona::getTelefono(){
	return _telefono;
}

const char *Persona::getEmail(){
	return _email;
}

Fecha Persona::getFechaNacimiento() {
    return _fechaNacimiento;
}


//Otros metodos
bool Persona::cargar() {
    cout << "ID: " << _idPersona << endl;

    // === DNI ===
    cout << "DNI (* para volver): ";

    while (true) {
        _dni = leerEnteroConIntentos(3);

        if (_dni == -1) return false;   
        if (_dni == 0) return false;    

        if (_dni >= 1000000 && _dni <= 99999999) {
            break;
        }

        cout << "Error: DNI debe tener entre 7 y 8 digitos. Ingrese nuevamente: ";
    }

    // === NOMBRE ===
    if (!leerNombreApellido(_nombre, 30, "Nombre")) {
        return false;
    }

    // === APELLIDO ===
    if (!leerNombreApellido(_apellido, 30, "Apellido")) {
        return false;
    }

    // === TELEFONO ===
    cout << "Telefono (* para volver): ";
    cin.getline(_telefono, 15);
    if (volverAtras(_telefono)) {
        return false;
    }
    while (!validarTelefono(_telefono, 7, 15)) {
        cout << "Error: telefono invalido. Ingrese nuevamente (* para volver): ";
        cin.getline(_telefono, 15);
        if (volverAtras(_telefono)) return false;
    }

    // === EMAIL ===
    cout << "Email (* para volver): ";
    cin.getline(_email, 30);
    if (volverAtras(_email)) {
        return false;
    }
    while (!validarEmail(_email)) {
        cout << "Error: email invalido. Ingrese nuevamente (* para volver): ";
        cin.getline(_email, 30);
        if (volverAtras(_email)) return false;
    }

    // === FECHA ===
    cout << "Fecha de nacimiento (* para volver): \n";
    if (!_fechaNacimiento.cargar()) {   
        return false;
    }

    return true;
}


void Persona::mostrar() {
    cout << left << setw(20) << "ID: "           << _idPersona << endl;
    cout << left << setw(20) << "Nombre:"           << _nombre << " " << _apellido << endl;
    cout << left << setw(20) << "DNI:"              << _dni << endl;
    cout << left << setw(20) << "Telefono:"         << _telefono << endl;
    cout << left << setw(20) << "Email:"            << _email << endl;
    cout << left << setw(20) << "Fecha Nacimiento:" << _fechaNacimiento.toString() << endl;
}

void Persona::mostrarNombreApellido() {
    cout << _apellido << " " << _nombre << " (ID:" << _idPersona << ")" << endl;
}

