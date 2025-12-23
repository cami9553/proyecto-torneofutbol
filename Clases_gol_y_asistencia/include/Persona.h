#ifndef PERSONA_H
#define PERSONA_H

#include "Fecha.h"
#include <iostream>
#include <string>

class Persona
{
private:
    int _idPersona;
    int _dni;
    char _apellido[30];
    char _nombre[30];
    char _telefono[30];
    char _email[30];
    Fecha _fechaNacimiento;
    static int _ultimoId;

public:
    Persona();
    Persona(int dni, const char* apellido, const char* nombre, const char* telefono, const char* email, Fecha fechaNacimiento);

    // Setters
    void setDni(int dni);
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setTelefono(std::string telefono);
    void setEmail(std::string email);
    void setFechaNacimiento(Fecha f);
    void setId(int id);

    // Getters
    int getDni();
    int getId() const;
    const char* getNombre();
    const char* getApellido();
    const char* getTelefono();
    const char* getEmail();
    Fecha getFechaNacimiento();

    // Métodos de ID
    static int getUltimoId();
    static void setUltimoId(int ultimoId);
    void generarNuevoId();

    // Otros métodos
    bool cargar();
    void mostrar();
    void mostrarNombreApellido();
};

#endif // PERSONA_H
