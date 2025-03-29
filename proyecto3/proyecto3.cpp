#include "NordSecurity.h"
#include <windows.h>
#include "colas.h"
void CentrarVentana() {
    HWND consola = GetConsoleWindow(); // Obtiene la ventana de la consola
    RECT rectPantalla;
    GetWindowRect(GetDesktopWindow(), &rectPantalla); // Obtiene el tamaño de la pantalla

    // Dimensiones de la consola
    RECT rectConsola;
    GetWindowRect(consola, &rectConsola);

    int anchoConsola = rectConsola.right - rectConsola.left;
    int altoConsola = rectConsola.bottom - rectConsola.top;

    // Calcula las nuevas coordenadas para centrar la ventana
    int posX = (rectPantalla.right - anchoConsola) / 2;
    int posY = (rectPantalla.bottom - altoConsola) / 2;

    // Mueve la ventana de la consola al centro
    MoveWindow(consola, posX, posY, anchoConsola, altoConsola, TRUE);
}
int main() {

    CentrarVentana(); // Llama a la función para centrar la ventana

    NordSecurity  seguridad;


    // Mostrar encabezado
    seguridad.imprimirEncabezado();

    // Ejecutar el menú principal
    while (true) {
        int opcion = seguridad.Menu();

        switch (opcion) {
        case 0:
            std:: cout << "Seguridad Física(Pila) seleccionada.\n";
            break;
        case 1:
            std::cout << "Seguridad en el Transporte de Valores(Pila) seleccionada.\n";
            break;
        case 2:
            std::cout << "Protección de Personas (VIP)(Pila) seleccionada.\n";
            break;
        case 3:
            std::cout << "Monitoreo de Alarmas y Respuesta Rápida seleccionada.\n";
            break;
        case 4:
            std::cout << "Servicios de Vigilancia seleccionados.\n";
            break;
        case 5:
            std::cout << "Capacitación seleccionada.\n";
            break;
        case 6:
            std::cout << "Saliendo...\n";
              
        }
    }

    return 0;
}
