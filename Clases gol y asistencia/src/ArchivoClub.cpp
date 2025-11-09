#include "Fecha.h"
#include "Club.h"
#include "ArchivoClub.h"

ArchivoClub::ArchivoClub(const std::string& nombreArchivo){
    _nombreArchivo = nombreArchivo;
    clubes = nullptr;
    cantidadClubes = 0;
    cargarDesdeArchivo();
}

ArchivoClub::~ArchivoClub() {
    delete[] clubes;
}


void ArchivoClub::cargarDesdeArchivo() {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb");
    if (pFile == NULL) {
        cantidadClubes = 0;
        clubes = nullptr;
        return;
    }

    fseek(pFile, 0, SEEK_END);
    int tam = ftell(pFile);
    cantidadClubes = tam / sizeof(Club);
    rewind(pFile);

    delete[] clubes;
    clubes = new Club[cantidadClubes];
    fread(clubes, sizeof(Club), cantidadClubes, pFile);

    fclose(pFile);
}



bool ArchivoClub::guardar(Club club){
    FILE* pFile = fopen(_nombreArchivo.c_str(), "ab");
    if (pFile == NULL) {
        std::cout << "Error al abrir el archivo para guardar.\n";
        return false;
    }

    bool ok = fwrite(&club, sizeof(Club), 1, pFile);
    fclose(pFile);

    // Actualizar la memoria dinámica
    Club* aux = new Club[cantidadClubes + 1];
    for (int i = 0; i < cantidadClubes; i++) {
        aux[i] = clubes[i];
    }
    aux[cantidadClubes] = club;

    delete[] clubes;
    clubes = aux;
    cantidadClubes++;

    return ok;
}

bool ArchivoClub::actualizar(Club club, int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL){
        return false;
    }
    fseek(pArchivo, sizeof(Club) * posicion, SEEK_SET);
    bool ok = fwrite(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

int ArchivoClub::buscar(int idClub){
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

Club ArchivoClub::leerRegistro(int posicion){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return Club();
    }
    Club club;
    fseek(pArchivo, sizeof(Club) * posicion, SEEK_SET);
    fread(&club, sizeof(Club), 1, pArchivo);
    fclose(pArchivo);
    return club;
}

int ArchivoClub::cantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Club);
    fclose(pArchivo);
    return cantidadRegistros;
}

void ArchivoClub::leer(int cantidadRegistros, Club *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Club), 1, pArchivo);
    }
    fclose(pArchivo);
}

Club* ArchivoClub::buscarPorId(int id) {
    for (int i = 0; i < cantidadClubes; i++) {
        if (clubes[i].getIdClub() == id) {
            return &clubes[i];
        }
    }
    return nullptr; // Por si no se encuentra el club
}

Club* ArchivoClub::getClubes() const {
    return clubes;
}
