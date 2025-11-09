#include "Fecha.h"
#include "ArchivoTorneo.h"

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
    int cantidadRegistros = ftell(pArchivo) / sizeof(Torneo);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoTorneo::Leer(int cantidadRegistros, Torneo *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Torneo), 1, pArchivo);
    }
    fclose(pArchivo);
}
