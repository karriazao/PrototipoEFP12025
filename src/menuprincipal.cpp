#include "menuprincipal.h"
#include "menuarchivo.h"
#include "menucatalogo.h"
#include "usuarios.h"
#include "bitacora.h"
#include <vector>
#include <iostream>

using namespace std;
void MenuPrincipal::mostrar(std::vector<Clientes>& clientes,
                          usuarios& usuarioActual) {
    int choice;
    do {
        system("cls");

        cout << "\t\t========================================\n"
             << "\t\t|     SISTEMA DE GESTION LOGISTICA     |\n"
             << "\t\t========================================\n"
             << "\t\t| Usuario: " << usuarioActual.getNombre() << "\n"
             << "\t\t================================================\n"
             << "\t\t 1. Archivo\n"
             << "\t\t 2. Catalogos\n"
             << "\t\t 3. Bitacora\n"
             << "\t\t 4. Salir\n"
             << "\t\t========================================\n"
             << "\t\tIngresa tu opcion: ";

        cin >> choice;

        switch(choice) {
            case 1:
                MenuArchivo::mostrar();
                break;

            case 2:
                MenuCatalogos::mostrar(clientes, usuarioActual);
                break;

            case 3: {
                bitacora b;
                b.menuBitacora();
                break;
            }

            case 4:
                return;

            default:
                cout << "\n\t\tOpcion invalida... Intenta de nuevo...";
        }
    } while(choice != 4);
}
