#include "colas.h"

void GestorRiesgos::insertarDatoCola(const STV& riesgo) {
    colaRiesgos.push(riesgo);
}

// Muestra una evaluaci�n de riesgo espec�fica
void mostrarEvaluacion(const STV& evaluacion) {
    cout << "\n--- Evaluaci�n de Riesgo ---\n";
    cout << "PlanRutas: " << evaluacion.PlanRutas << endl;
    cout << "DistRecorrer: " << evaluacion.DistRecorrer << endl;
    cout << "Tr�fico: " << evaluacion.Tr�fico << endl;
    cout << "TiemLlegada: " << evaluacion.TiemLlegada << endl;
    cout << "TiempoRuta: " << evaluacion.TiempoRuta << endl;
    cout << "CapMaximaPasajeros: " << evaluacion.CapMaximaPasajeros << endl;
    cout << "CostoCombustible: " << evaluacion.CostoCombustible << endl;
    cout << "HrsTotalesConductores: " << evaluacion.HrsTotalesConductores << endl;
    cout << "---------------------------\n";
}

// Muestra todas las evaluaciones en la cola
void GestorRiesgos::mostrarDatosCola() const {
    if (colaRiesgos.empty()) {
        cout << "No hay datos almacenados.\n";
        return;
    }

    queue<STV> temp = colaRiesgos;
    int contador = 1;

    cout << "\n=== Lista de Evaluaciones de Riesgo ===\n";
    while (!temp.empty()) {
        cout << "\nEvaluaci�n No.: " << contador++ << "\n";
        mostrarEvaluacion(temp.front());
        temp.pop();
    }
}

// Elimina el primer dato de la cola
void GestorRiesgos::eliminarDatoCola() {
    if (colaRiesgos.empty()) {
        cout << "No hay datos para eliminar.\n";
        return;
    }

    cout << "Eliminando la siguiente evaluaci�n:\n";
    mostrarEvaluacion(colaRiesgos.front());
    colaRiesgos.pop();
}

// Permite ingresar una nueva evaluaci�n de riesgos
void GestorRiesgos::ingresarDatosCola() {
    STV nuevoRiesgo;
    char opcion;

    do {
        system("cls");

        cout << "\nIngrese los datos de la evaluaci�n de riesgos:\n";
        cin.ignore();  // Limpia el buffer antes de leer strings

        cout << "Plan de Rutas: ";
        getline(cin, nuevoRiesgo.PlanRutas);

        cout << "Distancia a Recorrer: ";
        getline(cin, nuevoRiesgo.DistRecorrer);

        cout << "Tr�fico: ";
        getline(cin, nuevoRiesgo.Tr�fico);

        cout << "Tiempo de Llegada: ";
        cin >> nuevoRiesgo.TiemLlegada;
        cin.ignore();  // Ignora el salto de l�nea despu�s del n�mero

        cout << "Tiempo de Ruta: ";
        cin >> nuevoRiesgo.TiempoRuta;
        cin.ignore();

        cout << "Capacidad M�xima de Pasajeros: ";
        cin >> nuevoRiesgo.CapMaximaPasajeros;
        cin.ignore();

        cout << "Costo de Combustible: ";
        cin >> nuevoRiesgo.CostoCombustible;
        cin.ignore();

        cout << "Horas Trabajadas: ";
        cin >> nuevoRiesgo.HrsTotalesConductores;
        cin.ignore();

        insertarDatoCola(nuevoRiesgo);  // Llamamos a la funci�n para insertar el dato en la cola
        cout << "Evaluaci�n agregada correctamente.\n";

        cout << "�Desea ingresar otra evaluaci�n? (s/n): ";
        cin >> opcion;

    } while (opcion == 's' || opcion == 'S');
}


// Men� interactivo para la gesti�n de evaluaciones de riesgos
void GestorRiesgos::menuCola() {
    int opcion;

    do {
        system("cls");
        cout << "\n--- Men� de Evaluaciones de Riesgo ---\n";
        cout << "1. Insertar nueva evaluaci�n\n";
        cout << "2. Eliminar evaluaci�n m�s antigua\n";
        cout << "3. Mostrar todas las evaluaciones\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            ingresarDatosCola();
            break;
        case 2:
            eliminarDatoCola();
            break;
        case 3:
            mostrarDatosCola();
            break;
        case 4:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opci�n no v�lida. Intente de nuevo.\n";
            break;
        }
        system("pause");

    } while (opcion != 4);
}