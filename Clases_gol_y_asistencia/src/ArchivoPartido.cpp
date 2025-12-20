#include "ArchivoPartido.h"
#include "ArchivoClub.h"
#include "ArchivoGol.h"
#include "ArchivoJugador.h"
#include "Gol.h"
#include "Validaciones.h"
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

void ArchivoPartido::leerTodos(Partido* vector, int CantidadRegistros)
{
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) return;

    fread(vector, sizeof(Partido), CantidadRegistros, pFile);
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
            std::cout << "Error: no se encontro uno de los clubes del partido #"
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
    ArchivoJugador archivoJug("jugadores.dat");
    ArchivoGol archGol("goles.dat");
    archGol.cargarDesdeArchivo();

    FILE* pFile = fopen("partidos.dat", "rb+");
    if (pFile == NULL)
    {
        std::cout << "No se pudo abrir el archivo de partidos." << std::endl;
        return;
    }

    int nroPartido;
    std::cout << "Ingrese el numero de partido que desea registrar: ";
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
                std::cout << "Error: no se encontro uno de los clubes del partido." << std::endl;
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

            std::cout << "\nFecha del partido:\n";
            fechaJugado.cargar();

            // Actualizar datos del partido
            partido.setGolesLocal(golesLocal);
            partido.setGolesVisitante(golesVisitante);
            partido.setFecha(fechaJugado);

            // Registrar los goles en goles.dat
            Gol g;
            int dniJugador, idJugadorLocal, idJugadorVisitante, tipoGol;
            system("cls");

            std::cout << "\n====================================\n";
            std::cout << "CARGA DE GOLES - " << clubLocal.getNombre() << "\n";
            std::cout << "====================================\n";

            // Goles del local
            std::cout << "Jugadores de " << clubLocal.getNombre() << std::endl;
            archivoJug.listarJugadorPorClub(clubLocal.getIdClub());

            for (int i = 0; i < golesLocal; i++) {
                std::cout << "\nGol " << (i + 1) << " de " << golesLocal << " (ID del jugador): ";
                bool flag = true;
                while(flag){
                    std::cin >> idJugadorLocal;
                    if( validarJugadoryClub(idJugadorLocal, clubLocal.getIdClub()) ){
                        dniJugador = archivoJug.obtenerDni(idJugadorLocal);
                        flag = false;
                    }
                    else
                        std::cout << "\nIngrese nuevamente el ID: ";
                }

                std::cout << "Tipo de gol 1=Penal, 2=Cabeza, 3=Tiro libre: ";
                tipoGol = leerEnteroEnRango(1,3);

                g.setNroPartido(nroPartido);
                g.setDniJugador(dniJugador);
                g.setTipoGol(tipoGol);

                archGol.agregarGol(g);
            }

            // Goles del visitante - Falta agregar validacion de jugadores que juegan en este clubVisitante
            std::cout << "\n====================================\n";
            std::cout << "CARGA DE GOLES - " << clubVisitante.getNombre() << "\n";
            std::cout << "====================================\n";
            std::cout << "Jugadores de " << clubVisitante.getNombre() << std::endl;

            archivoJug.listarJugadorPorClub(clubVisitante.getIdClub());
            for (int i = 0; i < golesVisitante; i++) {
                std::cout << "\nGol " << (i + 1) << " de " << golesVisitante << " (ID del jugador): ";
                bool flag = true;
                while(flag){
                    std::cin >> idJugadorVisitante;
                    if( validarJugadoryClub(idJugadorVisitante, clubVisitante.getIdClub()) ){
                        dniJugador = archivoJug.obtenerDni(idJugadorVisitante);
                        flag = false;
                    }
                    else
                        std::cout << "\nIngrese nuevamente el ID: ";
                }

                std::cout << "Tipo de gol 1=Penal, 2=Cabeza, 3=Tiro libre: ";
                tipoGol = leerEnteroEnRango(1,3);

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
            std::cout << "\nPartido y goles registrados con exito.\n";

            break;
        }
    }

    if (!encontrado)
        std::cout << "No se encontr� el partido con el n�mero ingresado.\n";

    fclose(pFile);
}

