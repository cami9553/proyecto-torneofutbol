#include "Fecha.h"
#include "ArchivoTorneo.h"
#include "ArchivoClub.h"
#include "ArchivoPartido.h"
#include "Validaciones.h"

ArchivoTorneo::ArchivoTorneo(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoTorneo::Guardar(Torneo torneo){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&torneo, sizeof(Torneo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoTorneo::Guardar(Torneo torneo, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Torneo) * posicion, SEEK_SET);
    bool ok = fwrite(&torneo, sizeof(Torneo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoTorneo::Buscar(int idTorneo){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Torneo torneo;
    int i = 0;
    while(fread(&torneo, sizeof(Torneo), 1, pArchivo)){
        if(torneo.getIdTorneo() == idTorneo){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Torneo ArchivoTorneo::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Torneo();
    }
    Torneo torneo;
    fseek(pArchivo, sizeof(Torneo) * posicion, SEEK_SET);
    fread(&torneo, sizeof(Torneo), 1, pArchivo);
    fclose(pArchivo);
    return torneo;
}

int ArchivoTorneo::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int CantidadRegistros = ftell(pArchivo) / sizeof(Torneo);
    fclose(pArchivo);
    return CantidadRegistros;
}

void ArchivoTorneo::Leer(int CantidadRegistros, Torneo *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < CantidadRegistros; i++){
        fread(&vector[i], sizeof(Torneo), 1, pArchivo);
    }
    fclose(pArchivo);
}

/* *********************** Creador de fiture ********************************/

void ArchivoTorneo::crearFixture(int idTorneo) {
    ArchivoClub archClub;
    ArchivoPartido archPartido("partidos.dat");

    int cantClubes = archClub.CantidadRegistros();
    if (cantClubes < 2) {
        std::cout << "Se necesitan al menos 2 clubes para crear el fixture." << std::endl;
        return;
    }

    Club c1, c2;
    Partido p;
    Fecha f;
    int nroPartido = 1;
    int nroFecha = 1;
    int partidosPorFecha = cantClubes / 2; // ver si podemos dividir por jornadas (misma fecha)
    int contadorPartidosFecha = 0;

    for (int i = 0; i < cantClubes; i++) {
        c1 = archClub.leerRegistro(i);

        for (int j = i + 1; j < cantClubes; j++) {
            c2 = archClub.leerRegistro(j);

            p.setNroPartido(nroPartido++);
            p.setIdTorneo(idTorneo);
            p.setIdClubLocal(c1.getIdClub());
            p.setIdClubVisitante(c2.getIdClub());
            p.setGolesLocal(0);
            p.setGolesVisitante(0);
            p.setFecha(f);
            p.setJugado(false);

            archPartido.guardarRegistro(p);

            contadorPartidosFecha++;
            if (contadorPartidosFecha >= partidosPorFecha) {
                nroFecha++;
                contadorPartidosFecha = 0;
            }
        }
    }

    std::cout << "\nFixture creado con exito." << std::endl;
    std::cout << "Se generaron " << (nroPartido - 1) << " partidos"<< std::endl;
}

