#include "Fecha.h"
#include "Club.h"
#include "ArchivoClub.h"
#include "Validaciones.h"


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
        Club::setUltimoId(0);
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

    int maxId = 0;
    for (int i = 0; i < cantidadClubes; i++) {
        if (clubes[i].getIdClub() > maxId) {
            maxId = clubes[i].getIdClub();
        }
    }

    Club::setUltimoId(maxId);
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

int ArchivoClub::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int CantidadRegistros = ftell(pArchivo) / sizeof(Club);
    fclose(pArchivo);
    return CantidadRegistros;
}

void ArchivoClub::leer(int CantidadRegistros, Club *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < CantidadRegistros; i++){
        fread(&vector[i], sizeof(Club), 1, pArchivo);
    }
    fclose(pArchivo);
}

void ArchivoClub::listarRegistros() {
    int cantidad = CantidadRegistros();
    if (cantidad == 0) {
        std::cout << "No hay clubes registrados.\n";
        return;
    }

    Club C;
    std::cout << "\n=== LISTA DE CLUBES ===\n";
    for (int i = 0; i < cantidad; i++) {
        C = leerRegistro(i);
        std::cout << "\nClub #" << i + 1 << std::endl;
        C.mostrar();
    }
}

bool ArchivoClub::modificarRegistro(const Club& club, int posicion) {
    FILE* pFile = fopen(_nombreArchivo.c_str(), "rb+");
    if (pFile == NULL) return false;

    fseek(pFile, posicion * sizeof(Club), SEEK_SET);
    bool ok = fwrite(&club, sizeof(Club), 1, pFile);
    fclose(pFile);
    return ok;
}

Club* ArchivoClub::buscarPorId(int id) {
    cargarDesdeArchivo();
    for (int i = 0; i < cantidadClubes; i++) {
        if (clubes[i].getIdClub() == id) {
            return &clubes[i];
        }
    }
    return nullptr; // Por si no  encuentra el club
}

Club* ArchivoClub::getClubes() const {
    return clubes;
}

bool ArchivoClub::eliminarRegistroFisico(int id)
{
    Club club;
    FILE *p = fopen("clubes.dat", "rb");
    FILE *temp = fopen ("temp.dat", "wb");
    if (p == NULL || temp == NULL) return false;

while (fread(&club, sizeof(Club), 1, p))
{
    if (club.getIdClub() != id)
    {
        fwrite(&club, sizeof(Club), 1, temp);
    }
}
fclose(p);
fclose(temp);
remove("clubes.dat");
rename("temp.dat", "clubes.dat");
return true;
}
