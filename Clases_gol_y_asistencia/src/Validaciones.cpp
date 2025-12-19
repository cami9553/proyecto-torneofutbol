#include <iostream>
#include "Validaciones.h"
#include "ArchivoJugador.h"
#include <limits>
#include <string>
#include <cstring>

using namespace std;

int leerEnteroConIntentos(int maxIntentos) {
    int num;
    int intentos = 0;

    while (intentos < maxIntentos) {
        cin >> num;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            intentos++;
            cout << "Error: debe ingresar un numero. Intente de nuevo: ";
        } else {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          return num;
        }
      }
      cout << "Se alcanzo el maximo de intentos." << endl;
      return -1;
}


int leerEnteroEnRango(int min, int max) {
    int valor;
    do {
        valor = leerEnteroConIntentos(3);
        if (valor == -1) return -1;
        if (valor < min || valor > max) {
            cout << "Error: El valor debe estar entre " << min << " y " << max << ". Intente nuevamente: ";
        }
    } while (valor < min || valor > max);
    return valor;
}

// validacion para opcion si o no (S/N)
char leerOpcionSN() {
    char opcion;
    string entrada;

    while (true) {
        getline(cin, entrada);

        if (entrada.length() == 1) {
            opcion = toupper(entrada[0]);
            if (opcion == 'S' || opcion == 'N') {
                return opcion;
            }
        }
        cout << "Error: Debe ingresar 'S' o 'N'. Intente nuevamente: ";
    }
}

bool validarSoloLetrasEspacios(const char* texto) {
    for(int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];

        if(!((c >= 'A' && c <= 'Z') ||
             (c >= 'a' && c <= 'z') ||
             c == ' ' ||
             c == '.' ||
             c == '\'')) {
            return false;
        }
    }
    return true;
}


void leerNombreApellido(char* campo, int tamano, const char* mensaje) {
    cout << mensaje;
    while(true) {
        cin.getline(campo, tamano);

        // Verificar si está vacío
        if(campo[0] == '\0') {
            cout << "Error: No puede estar vacio. Ingrese " << mensaje;
            continue;
        }

        // verificar que solo sea letras y espacios
        if(validarSoloLetrasEspacios(campo)) {
            break;
        } else {
            cout << "Error: Solo puede contener letras y espacios. Ingrese " << mensaje;
        }
    }
}

void leerTextoValido(char* campo, int tamano, const char* mensaje) {
    cout << mensaje;
    while (true) {
        cin.getline(campo, tamano);

        if (campo[0] == '\0') {
            cout << "Error: no puede estar vacio." << mensaje;
            continue;
        }

        if (validarSoloLetrasEspacios(campo)) {
            break;
        } else {
            cout << "Error: Solo puede contener letras y espacios. Ingrese " << mensaje;
        }
    }

}

bool validarTelefono(const char* texto, int minDigitos, int maxDigitos) {
    int i = 0;

    // contar caracteres y validar que sean numeros
    while (texto[i] != '\0') {
        if (texto[i] < '0' || texto[i] > '9') { //ASCII
            return false;
        }
        i++;
    }

    // validar longitud
    if (i < minDigitos || i > maxDigitos) {
        return false;
    }

    return true;
}

void leerTelefono(char* telefono, int tamanio, int minDigitos, int maxDigitos) {
    while (true) {
        cin.getline(telefono, tamanio);

        // Validacion para cuando se excede de digitos
        if (cin.fail()) {
            cin.clear(); // limpia el error
            cin.ignore(1000, '\n'); // descarta lo que sobra
            cout << "Error: telefono demasiado largo.\nIntente nuevamente: ";
            continue;
        }

        if (validarTelefono(telefono, minDigitos, maxDigitos)) {
            return;
        }

        cout << "Error: telefono invalido. Solo numeros y entre " << minDigitos << " y " << maxDigitos << " digitos.\nIntente nuevamente: ";
    }
}


bool validarEmail(const std::string& email)
{
    int posArroba = -1;

    for (int i = 0; i < email.size(); i++)
    {
        if (email[i] == ' ')
        return false;

        if (email[i] == '@')
        {

            if (posArroba != -1) return false;
            posArroba = i;
        }
    }

    if (posArroba <= 0 || posArroba == email.size() - 1)
    return false;

    for (int i = posArroba + 1; i< email.size(); i++)
    {
        if (email[i] == '.')
        return true;
    }
    return false;
}

bool validarJugadoryClub(int idJugador, int idClub){
    ArchivoJugador archivoJug("jugadores.dat");

    return archivoJug.verificarClub(idJugador, idClub);
}
