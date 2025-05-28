#ifndef MENUCATALOGO_H
#define MENUCATALOGO_H

// Incluye las bibliotecas necesarias
#include <vector>            // Para usar contenedores vector
#include "Clientes.h"        // Manejo de clientes
#include "usuarios.h"        // Control de usuarios

// Clase para el men� de cat�logos del sistema
class MenuCatalogos {
public:

    static void mostrar(std::vector<Clientes>& clientes,
                      usuarios& usuarioActual);
};

#endif // MENUCATALOGO_H
