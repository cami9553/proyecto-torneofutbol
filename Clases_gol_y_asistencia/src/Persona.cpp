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
    cout << "DNI: ";

    // pedir DNI hasta que sea valido o 0
    while(true) {
        _dni = leerEnteroConIntentos(3);

        if(_dni == 0) return false;  // Termina si es 0

        if(_dni >= 1000000 && _dni <= 99999999) {
            break;  // DNI válido, sale del while
        }

        cout << "Error: DNI debe tener entre 7 y 8 digitos. Ingrese nuevamente (0 para terminar): ";
    }

    cin.ignore();

    leerNombreApellido(_nombre, 30, "Nombre: ");
    leerNombreApellido(_apellido, 30, "Apellido: ");

    cout << "Telefono: ";
    leerTelefono(_telefono, 15, 7, 15);

    cout << "Email: ";
    cin.getline(_email, 30);

    cout << "Fecha de nacimiento: \n";
    _fechaNacimiento.cargar();

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

