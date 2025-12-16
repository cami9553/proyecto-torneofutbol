#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int leerEnteroConIntentos(int maxIntentos = 3);
int leerEnteroEnRango(int min, int max);
char leerOpcionSN();
bool validarSoloLetrasEspacios(const char* texto);
void leerNombreApellido(char* campo, int tamano, const char* mensaje);
void leerTextoValido(char* campo, int tamano, const char* mensaje);

#endif 
