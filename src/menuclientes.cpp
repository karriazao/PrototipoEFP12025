#include "menuclientes.h"
#include "Cclientes.h"

// Inclusi�n de librer�as est�ndar
#include <iostream>
#include <vector>
#include <string>
#include <limits> // Para manejo de entradas inv�lidas y limpieza de buffer

using namespace std;
void MenuClientes::mostrar(vector<Clientes>& listaClientes, usuarios& usuarioActual) {
    int opcion;
    string input;

    do {
        system("cls"); // Limpia pantalla antes de mostrar el men� principal
        cout << "\n--------------------------------------------------------------------------------\n";
        cout << "                        SISTEMA DE GESTION DE CLIENTES                          \n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "   Usuario actual: " << usuarioActual.getNombre() << "\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "   [1] Agregar cliente\n";
        cout << "   [2] Mostrar clientes\n";
        cout << "   [3] Modificar cliente\n";
        cout << "   [4] Eliminar cliente\n";
        cout << "   [5] Volver al menu principal\n";
        cout << "--------------------------------------------------------------------------------\n";
        cout << "                     Seleccione una opcion: ";

        // Validaci�n para asegurar que la entrada sea un n�mero v�lido
        while (!(cin >> opcion)) {
            cin.clear(); // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora entrada inv�lida
            cout << "\n   Entrada invalida. Ingrese un numero valido: ";
        }
        cin.ignore(); // Limpia el salto de l�nea residual del buffer

        switch (opcion) {
            case 1:
                system("cls"); // Limpia antes de ejecutar la acci�n
                Clientes::agregar(listaClientes, usuarioActual.getNombre());
                // NO system("pause"); porque 'agregar' ya pausa
                break;

            case 2:
                system("cls");
                Clientes::mostrar(listaClientes);
                // NO system("pause"); porque 'mostrar' ya pausa
                break;

            case 3: {
                system("cls");
                Clientes::mostrar(listaClientes);
                if (!listaClientes.empty()) {
                    cout << "\n   Ingrese ID del cliente a modificar: ";
                    getline(cin, input);

                    if (Clientes::esIdValido(input)) {
                        Clientes::modificar(listaClientes, usuarioActual.getNombre(), input);
                        // modificar ya pausa internamente
                    } else {
                        cout << "   ID no valido. Debe estar entre " << CODIGO_INICIAL
                             << " y " << CODIGO_FINAL << "\n";
                        system("pause"); // Pausa solo aqu� en caso de ID inv�lido
                    }
                }
                // NO system("pause"); adicional ac�
                break;
            }

            case 4: {
                system("cls");
                Clientes::mostrar(listaClientes);
                if (!listaClientes.empty()) {
                    cout << "\n   Ingrese ID del cliente a eliminar: ";
                    getline(cin, input);

                    if (Clientes::esIdValido(input)) {
                        Clientes::eliminar(listaClientes, usuarioActual.getNombre(), input);
                        // eliminar ya pausa internamente
                    } else {
                        cout << "   ID no valido. Debe estar entre " << CODIGO_INICIAL
                             << " y " << CODIGO_FINAL << "\n";
                        system("pause"); // Pausa solo aqu� en caso de ID inv�lido
                    }
                }
                // NO system("pause"); adicional ac�
                break;
            }

            case 5:
                Clientes::guardarEnArchivo(listaClientes);
                cout << "\n   Regresando al menu principal...\n";
                system("pause"); // Pausa para que el usuario vea mensaje de salida
                break;

            default:
                cout << "\n   Opcion invalida.\n";
                system("pause"); // Pausa para informar opci�n inv�lida
                break;
        }

    } while (opcion != 5);
}
