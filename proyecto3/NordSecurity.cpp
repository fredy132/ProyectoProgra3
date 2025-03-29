#include "NordSecurity.h"
#include "colas.h"

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <stack>
#include <string>
#include <cstdlib>

#include <locale>
using namespace std;

// Constructor
NordSecurity::NordSecurity() {
    cabeza = nullptr;  // Inicializamos la cabeza de la lista como nula
}

// Destructor
NordSecurity::~NordSecurity() {
    liberarMemoria();  // Liberar la memoria cuando el objeto sea destruido
}



// Función para limpiar la lista enlazada
void NordSecurity::limpiarDatos() {
    Nodo* temp;
    while (cabeza) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

// Función para mostrar los datos en forma de pila e ingresar datos en forma de pila



// Función para insertar un nuevo dato en la lista
void NordSecurity::insertarDato(const EvaluacionRiesgo& riesgo) {
    Nodo* nuevoNodo = new Nodo();  // Creamos un nuevo nodo
    nuevoNodo->dato = riesgo;      // Asignamos los datos al nodo
    nuevoNodo->siguiente = cabeza; // El siguiente nodo será el que estaba antes en la cabeza
    cabeza = nuevoNodo;            // Ahora el nuevo nodo será la cabeza de la lista
}

// Función para mostrar los datos almacenados en la lista
void NordSecurity::mostrarDatos() const {
    Nodo* actual = cabeza;  // Empezamos desde la cabeza de la lista
    while (actual) {
        const EvaluacionRiesgo& evaluacion = actual->dato;
        cout << "Activo a proteger: " << evaluacion.activoAproteger << endl;
        cout << "Amenazas: " << evaluacion.amenaza << endl;
        cout << "Vulnerabilidades: " << evaluacion.vulnerabilidad << endl;
        cout << "Entorno: " << evaluacion.entorno << endl;
        cout << "Escenario de riesgo: " << evaluacion.escenarioRiesgo << endl;
        cout << "Medidas de seguridad: " << evaluacion.medidasSeguridad << endl;
        cout << "Probabilidad de riesgo: " << evaluacion.probabilidadRiesgo << endl;
        cout << "---------------------------------\n";

        actual = actual->siguiente;  // Avanzamos al siguiente nodo
    }
}

// Función para liberar la memoria de la lista
void NordSecurity::liberarMemoria() {
    Nodo* actual = cabeza;
    while (actual) {
        Nodo* siguiente = actual->siguiente;  // Guardamos el siguiente nodo
        delete actual; // Liberamos el nodo actual
        actual = siguiente; // Avanzamos al siguiente nodo
    }
}

// Función para ingresar datos manualmente
void NordSecurity::ingresarDatos() {
    string Activopro, amenaza, vul, Entorno, riesgo, mseg, prorie;
    char opcion;

    do {
    
        cout << "\n Ingresar nuevo dato de evaluación de riesgos\n";
        cout << "Activo a proteger: ";
        cin.ignore();
        getline(cin, Activopro);
        cout << "Amenaza potenciales: ";
        getline(cin, amenaza);
        cout << "Vulnerabilidades en las instalaciones: ";
        getline(cin, vul);
        cout << "Entorno: ";
        getline(cin, Entorno);
        cout << "Escenario de riesgo: ";
        getline(cin, riesgo);
        cout << "Medidas de seguridad existentes: ";
        getline(cin, mseg);
        cout << "Probabilidad de ocurrencia del riesgo: ";
        getline(cin, prorie);

        // Creamos un objeto EvaluacionRiesgo y lo insertamos
        EvaluacionRiesgo nuevoRiesgo = { Activopro, amenaza, vul, Entorno, riesgo, mseg, prorie };
        insertarDato(nuevoRiesgo);
        cout << " Dato agregado correctamente.\n";

        cout << "¿Desea ingresar otro dato? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');;

}


////////////////////////////////////////////////////////////////////////

// Mueve el cursor a la posición deseada en la consola
void NordSecurity::gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Imprime texto con animación
void NordSecurity::imprimirTexto(const std::string& texto, int x, int y, int delay) {
    gotoxy(x, y);
    for (char c : texto) {
        std::cout << c;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}


// Muestra el encabezado animado
void NordSecurity::imprimirEncabezado() {
  
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    std::string texto[] = {
        " N   N  OOO  RRRR  DDDD      SSS  EEEEE  CCCC U   U RRRR  III TTTTT  Y   Y ",
        " NN  N O   O R   R D   D    S     E      C    U   U R   R  I    T    Y   Y ",
        " N N N O   O RRRR  D   D     SSS  EEEE   C    U   U RRRR   I    T     Y Y  ",
        " N  NN O   O R  R  D   D        S E      C    U   U R  R   I    T      Y   ",
        " N   N  OOO  R   R DDDD      SSS  EEEEE  CCCC  UUU  R   R III    T     Y   "
    };

    int x = 17, y = 7;
    for (const std::string& linea : texto) {
        imprimirTexto(linea, x, y++, 10);
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    imprimirTexto("BIENVENIDO A Nord Security", 30, 15, 50);

    _getch();
    system("cls");
}

// Muestra un menú interactivo con flechas
int NordSecurity::mostrarMenuInteractivo(const std::string opciones[], int n, int x, int y, int colorFondo) {
    int opcionSeleccionada = 0;
    int teclaPresionada = 0;

    while (true) {
        for (int i = 0; i < n; i++) {
            gotoxy(x, y + i);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (i == opcionSeleccionada) ? FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY : colorFondo);
            std::cout << opciones[i];
        }

        teclaPresionada = _getch();
        if (teclaPresionada == 224) { // Teclas de dirección
            teclaPresionada = _getch();
            if (teclaPresionada == 72) opcionSeleccionada = (opcionSeleccionada == 0) ? n - 1 : opcionSeleccionada - 1;
            if (teclaPresionada == 80) opcionSeleccionada = (opcionSeleccionada == n - 1) ? 0 : opcionSeleccionada + 1;
        }
        if (teclaPresionada == 13) return opcionSeleccionada;  // Enter selecciona la opción
    }
}
void menuCola();

// Muestra el menú principal
int NordSecurity::Menu() {

    const int OPCIONES = 7;
    int colorFondo = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    int x = 22, y = 5;

    std::string opciones[OPCIONES] = {
        "Seguridad Física(Pila)",
        "Seguridad en el Transporte de Valores(Pila)",
        "Protección de Personas (VIP)(Pila)",
        "Monitoreo de Alarmas y Respuesta Rápida(Cola)",
        "Servicios de Vigilancia y Seguridad en Eventos(Cola)",
        "Capacitación y Formación Continua(Cola)",
        "SALIR"
    };

    int opcionMenu = mostrarMenuInteractivo(opciones, OPCIONES, x, y, colorFondo);

    switch (opcionMenu) {
    case 0:
        system("cls");
        std::cout << "Has elegido Seguridad Fisica.\n";
        std::cout << "\n";
        menuseguridadfisica();
        break;
    case 1: std::cout << menuCola(); break;
    case 2: std::cout << "Has elegido Protección de Personas (VIP).\n"; break;
    case 3: std::cout << "Has elegido Monitoreo de Alarmas y Respuesta Rápida.\n"; break;
    case 4: std::cout << "Has elegido Servicios de Vigilancia y Seguridad en Eventos.\n"; break;
    case 5: std::cout << "Has elegido Capacitación y Formación Continua.\n"; break;
    case 6:
        std::cout << "Saliendo del sistema...\n";
        system("exit");
        // Termina la ejecución del programa
    }

    return opcionMenu;
}


int NordSecurity::menuseguridadfisica() {

    int opcion;
    std::string dato;

    do {
        system("cls");
        std::cout << "\n--- Submenú seguridad personal en pila ---\n";
        std::cout << "1. Insertar dato de evaluacion (pila)\n";
        std::cout << "2. Eliminar dato (pila)\n";
        std::cout << "3. Mostrar todos los datos(cola)\n";
        std::cout << "4. Volver al menú principal\n";
        std::cout << "5 Regresar al menú principal\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
        case 1:
            std::cout << "Ingrese los datos que se le pide:\n ";
            std::cout << "---------------------------------------------\n ";
            std::cout << "\n ";
            system("cls");
            ingresarDatos();
            break;
        case 2:
            // Acción para eliminar dato (puedes implementarlo más tarde).
            break;
        case 3:
            system("cls");
            std::cout << "Mostrar datos: ";
            std::cout << "---------------------------------------------\n ";
            std::cout << "\n ";
            mostrarDatos();
            break;
        case 4:
        case 5:
            std::cout << "Regresando al menú principal...\n";
            system("cls");
            return Menu();  // Volver al menú principal
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
            break;
        }
        system("pause");
    } while (opcion != 5);

    return 0; // Retorno para cumplir con la declaración de la función
}
