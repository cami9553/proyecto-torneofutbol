#ifndef PERSONA_H
#define PERSONA_H
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
        
    public:
        Persona();
        int getDni();
        void setDni(int dni);
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setTelefono(string telefono);
        void setEmail(string email); 
        const char *getNombre();
        const char *getApellido();
        const char *getTelefono();
        const char *getEmail();       
};
#endif // PERSONA_H
