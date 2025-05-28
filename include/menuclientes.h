#ifndef MENUCLIENTES_H
#define MENUCLIENTES_H

#include "Clientes.h"  // Incluye la definici�n de la clase Clientes
#include "usuarios.h"  // Incluye la definici�n de la clase usuarios
#include <vector>      // Necesario para utilizar std::vector


class MenuClientes {
public:
    static void mostrar(std::vector<Clientes>& listaClientes, usuarios& usuarioActual);
};
#endif // MENUCLIENTES_H
