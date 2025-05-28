#include "menucatalogo.h"
#include "Menuclientes.h"
#include <iostream>
#include <limits>

using namespace std;

// Implementacion del menu de catalogos
void MenuCatalogos::mostrar(vector<Clientes>& clientes,
                          usuarios& usuarioActual) {
    int opcion;

    do {
        // Limpiar la pantalla en cada iteraci�n
        system("cls");

        // Mostrar encabezado del men� con informaci�n del usuario
        cout << "\t\t====================================\n"
             << "\t\t|        MENU CATALOGOS           |\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t| Nivel: " << usuarioActual.getNivelAcceso() << "\n"
             << "\t\t====================================\n"
             << "\t\t1. Clientes\n"
        }

        // Opci�n para volver al men� principal
        cout << "\t\t2. Volver al menu principal\n"
             << "\t\t====================================\n"
             << "\t\tSeleccione una opcion: ";

        // Validar entrada del usuario (solo n�meros enteros)
        while(!(cin >> opcion)) {
            cin.clear(); // Limpiar estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar buffer
            cout << "\t\tEntrada invalida. Ingrese un numero: ";
        }
        cin.ignore(); // Limpiar el salto de l�nea sobrante

        // Ejecutar la acci�n correspondiente a la opci�n seleccionada
        switch(opcion) {
            case 1:
                // Llamar al men� de clientes
                MenuClientes::mostrar(clientes, usuarioActual);
                break;

            case 2:
                // Volver al men� principal (salir del bucle)
                return;

            default:
                // Mensaje para opciones no v�lidas
                cout << "\n\t\tOpcion invalida. Intente nuevamente.\n";
                system("pause");
        }

    } while(true); // Repetir hasta que el usuario seleccione la opci�n de salir
}
