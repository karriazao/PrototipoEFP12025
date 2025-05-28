#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <vector>              // Para usar contenedores vector
#include "usuarios.h"
#include "Clientes.h"


// Clase que implementa el men� principal del sistema
class MenuPrincipal {
public:
    static void mostrar(
        std::vector<Clientes>& clientes,
        usuarios& usuarioActual
    );
};
#endif // MENUPRINCIPAL_H
