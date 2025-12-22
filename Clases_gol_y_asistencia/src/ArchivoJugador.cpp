#include "ArchivoJugador.h"
#include "Validaciones.h"
#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

ArchivoJugador::ArchivoJugador(const std::string& nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
    inicializarUltimoId();
}

void ArchivoJugador::inicializarUltimoId()
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL)
    {
        Persona::setUltimoId(0);
        return;
    }

    Jugador j;
    int maxId = 0;

    while (fread(&j, sizeof(Jugador), 1, pFile))
    {
        if (j.getId() > maxId)
        {
            maxId = j.getId();
        }
    }

    fclose(pFile);
    Persona::setUltimoId(maxId);
}


int ArchivoJugador::getCantidadRegistros()
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return 0;

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);

    return tam / sizeof(Jugador);
}

Jugador ArchivoJugador::leerRegistro(int posicion) {
    Jugador jugador;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == NULL) {
        return jugador;
    }

    fseek(pFile, posicion * sizeof(Jugador), SEEK_SET);
    fread(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);

    return jugador;
}

bool ArchivoJugador::guardarRegistro(const Jugador& jugador) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == NULL) {
        return false;
    }

    bool ok = fwrite(&jugador, sizeof(Jugador), 1, pFile) > 0;
    fclose(pFile);
    return ok;
}

bool ArchivoJugador::modificarRegistro(const Jugador& jugador, int posicion)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == NULL) return false;

    fseek(pFile, posicion * sizeof(Jugador), SEEK_SET);
    bool ok = fwrite(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);
    return ok;
}

void ArchivoJugador::listarRegistros()
{
    int cantidad = getCantidadRegistros();
    if (cantidad == 0)
    {
        std::cout << "No hay jugadores registrados.\n";
        return;
    }

    Jugador J;
    std::cout << "\n=== LISTA DE JUGADORES ===\n";
    for (int i = 0; i < cantidad; i++)
    {
        J = leerRegistro(i);
        std::cout << "\nJugador #" << i + 1 << std::endl;
        J.mostrar();
    }
}

int ArchivoJugador::buscarPorDni(int dni)
{
    Jugador J;
    int cantidad = getCantidadRegistros();

    for (int i = 0; i < cantidad; i++)
    {
        J = leerRegistro(i);
        if (J.getDni() == dni)
        {
            return i;
        }
    }
    return -1;
}

int ArchivoJugador::buscarPorId(int id)
{
    Jugador j;
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        j = leerRegistro(i);
        if (j.getId() == id) return i;
    }
    return -1;
}


void ArchivoJugador::listarNombreApellido()
{
    int cantidad = getCantidadRegistros();
    if (cantidad == 0)
    {
        std::cout << "No hay jugadores registrados.\n";
        return;
    }

    Jugador J;
    for (int i = 0; i < cantidad; i++)
    {
        J = leerRegistro(i);
        J.mostrarNombreApellido();
    }
}

void ArchivoJugador::listarJugadorPorClub(int idClub)
{
    int cantidad = getCantidadRegistros();
    if (cantidad == 0)
    {
        std::cout << "No hay jugadores registrados.\n";
        return;
    }

    Jugador J;
    for (int i = 0; i < cantidad; i++)
    {
            J = leerRegistro(i);
            if(J.getIdClub() == idClub){
                cout <<"- ";
                J.mostrarNombreApellido();
            }

    }
}


int ArchivoJugador::obtenerDni(int idJugador)
{
    Jugador j;
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        j = leerRegistro(i);
        if (j.getId() == idJugador) return j.getDni();
    }
    return -1;
}


void ArchivoJugador::leerTodos(Jugador* vector, int CantidadRegistros)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fread(vector, sizeof(Jugador), CantidadRegistros, pFile);
    fclose(pFile);
}

bool ArchivoJugador::eliminarRegistroFisico(int dni)
{
    Jugador jugador;
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (p == NULL || temp == NULL) {
        return false;
    }

    while (fread(&jugador, sizeof(jugador), 1, p))
    {
        if (jugador.getDni() != dni)
        {
            fwrite(&jugador, sizeof(Jugador), 1, temp);
        }
    }

    fclose(p);
    fclose(temp);
    remove(_nombreArchivo.c_str());
    rename("temp.dat", _nombreArchivo.c_str());
    return true;
}

bool ArchivoJugador::verificarClub(int idJugador, int idClub){
    bool flag = false;
    int cantidad = getCantidadRegistros();
    if (cantidad == 0)
    {
        std::cout << "No hay jugadores registrados.\n";
        return flag;
    }

    Jugador J;
    for (int i = 0; i < cantidad; i++)
    {
            J = leerRegistro(i);
            if(J.getId() == idJugador)
                    if(J.getIdClub() == idClub)
                        return true;
                    else{
                        std::cout << "Error: ID incorrecto.";
                        return flag;
                    }
    }
    return flag;
}

bool ArchivoJugador::existeJugadorPorDni(int dni) {
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++) {
        Jugador J = leerRegistro(i);
        if (J.getDni() == dni) {
            return true;
        }
    }
    return false;
}
