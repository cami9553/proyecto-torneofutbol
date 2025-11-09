#include "Persona.h"
#include <cstring>
#include <iostream>
using namespace std;

Persona::Persona()
{
    _dni = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_telefono, "");
    strcpy(_email,"");
    Fecha _fechaNacimiento;

}

Persona::Persona(int dni, const char* apellido, const char* nombre, const char* telefono, const char* email, Fecha fechaNacimiento) {
    _dni = dni;
    strcpy(_apellido, apellido);
    strcpy(_nombre, nombre);
    strcpy(_telefono, telefono);
    strcpy(_email, email);
    _fechaNacimiento = fechaNacimiento;
}

//Setters
void Persona::setDni(int dni){
	_dni = dni;
}

void Persona::setApellido(const char* apellido){
    strcpy(_apellido, apellido);
}

void Persona::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}

void Persona::setTelefono(const char* telefono){
    strcpy(_telefono, telefono);
}

void Persona::setEmail(const char* email){
    strcpy(_email, email);
}

void Persona::setFechaNacimiento(Fecha f) {
    _fechaNacimiento = f;
}

//Getters
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
void Persona::cargar() {
    cout << "DNI: " << endl;
    cin >> _dni;
    cin.ignore();

    cout << "Nombre: "<< endl;
    cin.getline(_nombre, 30);

    cout << "Apellido: "<< endl;
    cin.getline(_apellido, 30);

    cout << "Telefono: "<< endl;
    cin.getline(_telefono, 15);

    cout << "Email: "<< endl;
    cin.getline(_email, 30);

    cout << "Fecha de nacimiento:" << endl;
    _fechaNacimiento.cargar();
}

void Persona::mostrar() {
    cout << "DNI: " << _dni << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Email: " << _email << endl;
    cout << "Fecha Nacimiento: " << _fechaNacimiento.toString() << endl;
}
