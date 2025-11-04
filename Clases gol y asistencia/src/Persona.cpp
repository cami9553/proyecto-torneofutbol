#include "Persona.h"
#include <cstring> 

Persona::Persona()
{
    _dni = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_telefono, "");
    strcpy(_email,"");	
	
}

void Persona::setDni(int dni){
	_dni = dni;
}

void Persona::setApellido(string apellido){
	strcpy(_apellido, apellido.c_str());
}

void Persona::setNombre(string nombre){
	strcpy(_nombre, nombre.c_str());
}

void Persona::setTelefono(string telefono){
	strcpy(_telefono, telefono.c_str());
}

void Persona::setEmail(string email){
	strcpy(_email, email.c_str());
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
