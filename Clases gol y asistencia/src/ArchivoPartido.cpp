#include "ArchivoPartido.h"
#include "ArchivoClub.h"
#include "ArchivoGol.h"
#include "Gol.h"
#include <cstdio>
#include <iostream>

ArchivoPartido::ArchivoPartido(const std::string& nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int ArchivoPartido::getCantidadRegistros()
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return 0;

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    fclose(pFile);

    return tam / sizeof(Partido);
}

Partido ArchivoPartido::leerRegistro(int posicion)
{
    Partido partido;
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return partido;

    fseek(pFile, posicion * sizeof(Partido), SEEK_SET);
    fread(&partido, sizeof(Partido), 1, pFile);
    fclose(pFile);

    return partido;
}

bool ArchivoPartido::guardarRegistro(const Partido& partido)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == NULL) return false;

    bool ok = fwrite(&partido, sizeof(Partido), 1, pFile);
    fclose(pFile);
    return ok;
}

bool ArchivoPartido::modificarRegistro(const Partido& partido, int posicion)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == NULL) return false;

    fseek(pFile, posicion * sizeof(Partido), SEEK_SET);
    bool ok = fwrite(&partido, sizeof(Partido), 1, pFile);
    fclose(pFile);
    return ok;
}

void ArchivoPartido::leerTodos(Partido* vector, int cantidadRegistros)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fread(vector, sizeof(Partido), cantidadRegistros, pFile);
    fclose(pFile);
}


bool ArchivoPartido::listarRegistros()
{
    ArchivoClub archClub("clubes.dat");

    FILE* pFile = fopen("partidos.dat", "rb");

    if (pFile == NULL)
    {
        std::cout << "No se pudo abrir el archivo de partidos." << std::endl;
        return false;
    }

    Partido partido;
    std::cout << "=== FIXTURE ===" << std::endl;

    while (fread(&partido, sizeof(Partido), 1, pFile) == 1)
    {
        int posLocal = archClub.buscar(partido.getIdClubLocal());
        int posVisitante = archClub.buscar(partido.getIdClubVisitante());

        if (posLocal == -1 || posVisitante == -1)
        {
            std::cout << "Error: no se encontró uno de los clubes del partido #"
                      << partido.getNroPartido() << std::endl;
            continue; //si hay algun error q muestre los demas igual
        }

        Club clubLocal = archClub.leerRegistro(posLocal);
        Club clubVisitante = archClub.leerRegistro(posVisitante);



        std::cout << "Partido #" << partido.getNroPartido() << ": "
                  << clubLocal.getNombre() << " vs " << clubVisitante.getNombre()<<std::endl;
         //" - Fecha: " << partido.getFecha().toString() << std::endl;
    }

    fclose(pFile);
    return true;
}

void ArchivoPartido::registrarResultado()
{
    ArchivoClub archClub("clubes.dat");
    ArchivoGol archGol("goles.dat");

    FILE* pFile = fopen("partidos.dat", "rb+");
    if (pFile == NULL)
    {
        std::cout << "No se pudo abrir el archivo de partidos." << std::endl;
        return;
    }

    int nroPartido;
    std::cout << "Ingrese el número de partido que desea registrar: ";
    std::cin >> nroPartido;

    Partido partido;
    bool encontrado = false;

    while (fread(&partido, sizeof(Partido), 1, pFile) == 1)
    {
        if (partido.getNroPartido() == nroPartido)
        {
            encontrado = true;

            int golesLocal, golesVisitante;
            Fecha fechaJugado;

            int posLocal = archClub.buscar(partido.getIdClubLocal());
            int posVisitante = archClub.buscar(partido.getIdClubVisitante());

            if (posLocal == -1 || posVisitante == -1)
            {
                std::cout << "Error: no se encontró uno de los clubes del partido." << std::endl;
                fclose(pFile);
                return;
            }

            Club clubLocal = archClub.leerRegistro(posLocal);
            Club clubVisitante = archClub.leerRegistro(posVisitante);

            std::cout << "\nRegistrando resultado para: "
                      << clubLocal.getNombre() << " vs " << clubVisitante.getNombre() << std::endl;

            std::cout << "Goles de " << clubLocal.getNombre() << ": ";
            std::cin >> golesLocal;
            std::cout << "Goles de " << clubVisitante.getNombre() << ": ";
            std::cin >> golesVisitante;

            std::cout << "\nFecha del partido (dd mm aaaa): ";
            int d, m, a;
            std::cout << "Dia: ";
            std::cin >> d;
            std::cout << "Mes: ";
            std::cin >> m;
            std::cout << "Anio: ";
            std::cin >> a;
            fechaJugado.setDia(d);
            fechaJugado.setMes(m);
            fechaJugado.setAnio(a);

            // Actualizar datos del partido
            partido.setGolesLocal(golesLocal);
            partido.setGolesVisitante(golesVisitante);
            partido.setFecha(fechaJugado);

            // Registrar los goles en goles.dat
            Gol g;
            int dniJugador, tipoGol;

            std::cout << "\n--- Registro de goles ---" << std::endl;

            // Goles del local - Falta agregar validacion de jugadores que juegan en este clubLocal
            for (int i = 0; i < golesLocal; i++) {
                std::cout << "\nGol #" << (i + 1) << " de " << clubLocal.getNombre() << std::endl;
                std::cout << "DNI del jugador: ";
                std::cin >> dniJugador;
                std::cout << "Tipo de gol (1=Penal, 2=Cabeza, 3=Tiro libre: ";
                std::cin >> tipoGol;

                g.setNroPartido(nroPartido);
                g.setDniJugador(dniJugador);
                g.setTipoGol(tipoGol);

                archGol.agregarGol(g);
            }

            // Goles del visitante - Falta agregar validacion de jugadores que juegan en este clubVisitante
            for (int i = 0; i < golesVisitante; i++) {
                std::cout << "\nGol #" << (i + 1) << " de " << clubVisitante.getNombre() << std::endl;
                std::cout << "DNI del jugador: ";
                std::cin >> dniJugador;
                std::cout << "Tipo de gol (1=Penal, 2=Cabeza, 3=Tiro libre, etc): ";
                std::cin >> tipoGol;

                g.setNroPartido(nroPartido);
                g.setDniJugador(dniJugador);
                g.setTipoGol(tipoGol);

                archGol.agregarGol(g);
            }

            // Guardar todos los goles al archivo
            archGol.guardarEnArchivo();

            // Sobrescribir el registro del partido con los datos que ingresamos
            fseek(pFile, -sizeof(Partido), SEEK_CUR);
            fwrite(&partido, sizeof(Partido), 1, pFile);
            std::cout << "\nPartido y goles registrados con éxito.\n";

            break;
        }
    }

    if (!encontrado)
        std::cout << "No se encontró el partido con el número ingresado.\n";

    fclose(pFile);
}

