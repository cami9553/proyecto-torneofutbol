#ifndef PERSONA_H
#define PERSONA_H
#include "Fecha.h"

#include <iostream>
#include <string>

class Persona
{
    private:
        int _dni;
        char _apellido[30];
        char _nombre[30];
        char _telefono[30];
        char _email[30];
        Fecha _fechaNacimiento;

    public:
        Persona();
        Persona(int dni, const char* apellido, const char* nombre, const char* telefono, const char* email, Fecha fechaNacimiento);
        int getDni();
        void setDni(int dni);
        void setNombre(std::string nombre);
        void setApellido(std::string apellido);
        void setTelefono(std::string telefono);
        void setEmail(std::string email);
        void setFechaNacimiento(Fecha f);
        const char *getNombre();
        const char *getApellido();
        const char *getTelefono();
        const char *getEmail();
        Fecha getFechaNacimiento();

        //Otros metodos
        bool cargar();
        void mostrar();
};
#endif // PERSONA_H
