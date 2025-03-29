#pragma once
#ifndef NORD_SECURITY_H
#define NORD_SECURITY_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <stack>
#include <string>
#include <cstdlib>

#include <vector>

using namespace std;

struct EvaluacionRiesgo {
    string activoAproteger;
    string amenaza;
    string vulnerabilidad;
    string entorno;
    string escenarioRiesgo;
    string medidasSeguridad;
    string probabilidadRiesgo;
};
struct Nodo {
    EvaluacionRiesgo dato;  // Contiene el dato de la evaluación de riesgo
    Nodo* siguiente;        // Puntero al siguiente nodo
};

// Clase NordSecurity
class NordSecurity {
public:

    // Métodos del menú
    void imprimirEncabezado();
    int Menu();
 
    NordSecurity();  // Constructor
    ~NordSecurity(); // Destructor

    // Métodos
 // Métodos
    void ingresarDatos();   // Función para ingresar datos manualmente
    void mostrarDatos() const; // Función para mostrar los datos ingresados
    void insertarDato(const EvaluacionRiesgo& riesgo);
 
    void limpiarDatos(); // Limpiar lista enlazada



    // Métodos auxiliares
    static void gotoxy(int x, int y);
    void imprimirTexto(const std::string& texto, int x, int y, int delay = 50);
    int mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo);
    int menuseguridadfisica();

private:
    Nodo* cabeza;  // Puntero al primer nodo de la lista enlazada
    void liberarMemoria(); // Función para liberar la memoria de la lista


  
 
    stack<string> pilaSeguridadFisica; // Lista enlazada para acciones
};



#endif
