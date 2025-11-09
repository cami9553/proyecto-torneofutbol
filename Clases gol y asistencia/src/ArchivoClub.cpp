#include "Fecha.h"
#include "ArchivoClub.h"

ArchivoClub::ArchivoClub(std::string nombreArchivo){
    _nombreArchivo = nombreArchivo;
}

bool ArchivoClub::Guardar(Club club){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL){
        return false;
    }
    bool ok = fwrite(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

bool ArchivoClub::Guardar(Club club, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Club) * posicion, SEEK_SET);
    bool ok = fwrite(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoClub::Buscar(int idClub){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return -1;
    }
    Club club;
    int i = 0;
    while(fread(&club, sizeof(Club), 1, pArchivo)){
        if(club.getIdClub() == idClub){
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

Club ArchivoClub::Leer(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Club();
    }
    Ckub club;
    fseek(pArchivo, sizeof(Club) * posicion, SEEK_SET);
    fread(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return club;
}

int ArchivoClub::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Club);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoClub::Leer(int cantidadRegistros, Club *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Club), 1, pArchivo);
    }
    fclose(pArchivo);
}
