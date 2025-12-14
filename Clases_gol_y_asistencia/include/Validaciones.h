#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int leerEntero();
int leerEnteroEnRango(int min, int max);
char leerOpcionSN();
bool validarSoloLetrasEspacios(const char* texto);
void leerNombreApellido(char* campo, int tamano, const char* mensaje);

#endif 
