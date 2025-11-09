#ifndef ARCHIVOASISTENCIA_H
#define ARCHIVOASISTENCIA_H

#include <string>
#include "Asistencia.h"

class Archivoasistencia {
private:
    Asistencia* _Asistencias;
    int _cantidadasistencias;
    std::string _nombreArchivo;

public:
    Archivoasistencia(const std::string& nombreArchivo);
    ~Archivoasistencia();

    int getCantidad() const;
    void agregarasistencia(const Asistencia& a);
    void buscarPorPartido(int idPartido);
    void cargarDesdeArchivo();
    void guardarEnArchivo();
};


#endif
