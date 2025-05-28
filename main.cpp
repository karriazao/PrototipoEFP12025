#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include "usuarios.h"
#include "MenuPrincipal.h"

int main() {
    std::cout << "Inicio del programa..." << std::endl;

    // Inicializar todas las listas necesarias


    // Cargar los datos desde archivos
    std::cout << "Cargando clientes..." << std::endl;
    Clientes::cargarDesdeArchivo(listaClientes);

    // Sistema de login
    if (usuarioRegistrado.loginUsuarios()) {
        std::cout << "Login exitoso.\n";
        MenuPrincipal::mostrar(
            listaClientes,
        );
    } else {
        std::cout << "Login fallido. Saliendo del programa.\n";
    }

    std::cout << "\n\t\t** Sistema de Logistica - Hasta pronto **\n";

    // Guardar datos actualizados
    std::cout << "Guardando clientes..." << std::endl;
    Clientes::guardarEnArchivo(listaClientes);

    system("pause");
    return 0;
}
