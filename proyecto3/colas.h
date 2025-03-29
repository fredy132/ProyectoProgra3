#ifndef COLAS_H
#define COLAS_H

#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Estructura para almacenar la evaluaci�n de riesgos
struct STV{
    string PlanRutas;
    string DistRecorrer;
    string Tr�fico;
    int TiemLlegada;
    int TiempoRuta;
    int CapMaximaPasajeros;
    int CostoCombustible;
    int HrsTotalesConductores;
};

// Clase que maneja la cola de evaluaciones de riesgo
class GestorRiesgos {
private:
    queue<STV> colaRiesgos; // Cola de evaluaciones

public:
    // M�todos para la gesti�n de la cola
    void insertarDatoCola(const STV& riesgo);
    void mostrarDatosCola() const;
    void eliminarDatoCola();
    void ingresarDatosCola();
    void menuCola();
};

#endif