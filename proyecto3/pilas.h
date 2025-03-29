#pragma once
#ifndef PILAS_H
#define PILAS_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <stack>
#include <string>

using namespace std;

// Estructura para la lista enlazada de acciones recomendadas
struct NodoAccion {
    string accion;
    NodoAccion* siguiente;
};

// Clase NordSecurity
class NordSecurity {
public:
    // Constructor y Destructor
    NordSecurity();
    ~NordSecurity();


    int Menu();


    // Métodos de Evaluación de Riesgo
    void agregarAccion(const string& accion);
    void mostrarAcciones() const;
    void mostrarEvaluacion() const;

    // Métodos auxiliares
    static void gotoxy(int x, int y);
    int mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo);

private:
    // Datos de Evaluación de Riesgo
    string activos;
    string amenazas[3];
    string vulnerabilidades[2];
    string entorno;
    string escenarios[2];
    string medidas[2];
    int probabilidadRiesgo;
    int tiempoRespuesta;

    NodoAccion* accionesRecomendadas;
    stack<string> pilaSeguridadFisica; // Lista enlazada para acciones
};

#endif
