#include "ArchivoJugador.h"
#include <cstdio>


ArchivoJugador::ArchivoJugador(const std::string& nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
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

Jugador ArchivoJugador::leerRegistro(int posicion)
{
    Jugador jugador;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return jugador;

    fseek(pFile, posicion * sizeof(Jugador), SEEK_SET);
    fread(&jugador, sizeof(Jugador), 1, pFile);
    fclose(pFile);

    return jugador;
}

bool ArchivoJugador::guardarRegistro(const Jugador& jugador)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == NULL) return false;

    bool ok = fwrite(&jugador, sizeof(Jugador), 1, pFile);
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

int ArchivoJugador::buscarPorId(int dni)
{
    Jugador j;
    int cantidad = getCantidadRegistros();
    for (int i = 0; i < cantidad; i++)
    {
        j = leerRegistro(i);
        if (j.getDni() == dni) return i;
    }
    return -1;
}

void ArchivoJugador::leerTodos(Jugador* vector, int cantidadRegistros)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fread(vector, sizeof(Jugador), cantidadRegistros, pFile);
    fclose(pFile);
}

bool ArchivoJugador::eliminarRegistroFisico(int dni)
{
    Jugador jugador;
    FILE *p = fopen("jugadores.dat","rb" );
    FILE *temp = fopen("temp.dat", "wb");
    if (p == NULL || temp == NULL) return false;

    while (fread(&jugador, sizeof(jugador), 1, p))
    {
        if (jugador.getDni() != dni)
        {
            fwrite(&jugador, sizeof(Jugador), 1, temp);
        }
    }
    fclose(p);
    fclose(temp);
    remove("jugadores.dat");
    rename("temp.dat", "jugadores.dat");
    return true;
}
