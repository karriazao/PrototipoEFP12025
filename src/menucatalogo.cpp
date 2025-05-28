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
             << "\t\t2. Proveedores\n"
             << "\t\t3. Productos\n"
             << "\t\t4. Almacenes\n"
             << "\t\t5. Transportistas\n";

        // Mostrar opci�n adicional si el usuario tiene nivel de acceso alto (admin)
        if(usuarioActual.getNivelAcceso() >= 3) {
            cout << "\t\t6. Administracion\n";
        }

        // Opci�n para volver al men� principal
        cout << "\t\t7. Volver al menu principal\n"
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
                // Llamar al men� de proveedores
                MenuProveedores::mostrar(proveedores, usuarioActual);
                break;

            case 3:
                // Llamar al men� de productos
                MenuProductos::mostrar(productos, usuarioActual);
                break;

            case 4:
                // Llamar al men� de almacenes
                MenuAlmacenes::mostrar(almacenes, usuarioActual);
                break;

            case 5:
                // Llamar al men� de transportistas
                MenuTransportistas::mostrar(transportistas, usuarioActual);
                break;

            case 6:
                // Solo disponible si el usuario tiene nivel 3 o superior
                if(usuarioActual.getNivelAcceso() >= 3) {
                    MenuAdministracion::mostrar(administradores, usuarioActual);
                } else {
                    // Si no tiene acceso, se muestra un mensaje de error
                    cout << "\n\t\tAcceso denegado. Nivel insuficiente.\n";
                    system("pause");
                }
                break;

            case 7:
                // Volver al men� principal (salir del bucle)
                return;

            default:
                // Mensaje para opciones no v�lidas
                cout << "\n\t\tOpcion invalida. Intente nuevamente.\n";
                system("pause");
        }

    } while(true); // Repetir hasta que el usuario seleccione la opci�n de salir
}
