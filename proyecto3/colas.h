#pragma once
#ifndef COLAS_H
#define COLAS_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <queue>  // Cambiamos <stack> por <queue>
#include <string>

using namespace std;

// Estructura para la lista enlazada de acciones recomendadas
struct NodoAccion {
    string accion;
    NodoAccion* siguiente;
};

// Clase NordSecurity
    // Constructor y Destructor
struct STV {
    string PlaniRutas;
    string DistRecorrer;
    string Tr�fico;
    int TiemLLegada;
    int TiemRuta;
    int CapPasajeros;
    int CostoCombustible;
    int HorasTrabajadas;

 };
   

    

    // M�todos de Evaluaci�n de Riesgo
    void agregarAccion(const string& accion);
    
    

    // M�todos auxiliares
    static void gotoxy(int x, int y);
    int mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo);


    
// Implementaci�n de m�todos modificar
void agregarMedidaSeguridad(const string& medida) {
    colaSeguridadFisica.push(medida);
}

string obtenerProximaMedida() {
    if (colaSeguridadFisica.empty()) {
        return "";  // Devuelve una cadena vac�a si la cola est� vac�a
    }
    string medida = colaSeguridadFisica.front();
    colaSeguridadFisica.pop();
    return medida;
}

bool hayMedidasSeguridad() const {
    return !colaSeguridadFisica.empty();
}

void agregarAccion(const string& accion) {
    // A�adir acci�n a la lista enlazada
    NodoAccion* nuevoNodo = new NodoAccion{ accion, accionesRecomendadas };
    accionesRecomendadas = nuevoNodo;

    // A�adir acci�n a la cola de seguridad f�sica
    colaSeguridadFisica.push(accion);  // Usamos push() para a�adir a la cola
}

void mostrarAcciones() const {
    // Mostrar acciones de la lista enlazada
    cout << "Acciones recomendadas:" << endl;
    NodoAccion* actual = accionesRecomendadas;
    while (actual != nullptr) {
        cout << "- " << actual->accion << endl;
        actual = actual->siguiente;
    }

    // Mostrar acciones de la cola de seguridad f�sica
    cout << "\nAcciones en la cola de seguridad f�sica:" << endl;
    queue<string> temp = colaSeguridadFisica;  // Copiamos la cola para no modificarla
    while (!temp.empty()) {
        cout << "- " << temp.front() << endl;
        temp.pop();
    }
}


void gotoxy(int x, int y) {
    // Posicionar el cursor en la consola
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo) {
    // Implementaci�n del men� interactivo
    // (Este m�todo no se modifica)
    return 0;
}

#endif // COLAS_H