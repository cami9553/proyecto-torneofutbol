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
