#ifndef CLIENTES_H
#define CLIENTES_H
#include <vector>
#include <string>

class Clientes {
private:
    /// Identificador �nico del cliente (formato secuencial, rango permitido: 3107�3157)
    std::string id;

    /// Nombre completo del cliente
    std::string nombre;

    /// Direcci�n f�sica del cliente
    std::string direccion;

    /// N�mero de tel�fono del cliente
    std::string telefono;

    /// N�mero de Identificaci�n Tributaria (NIT) del cliente
    std::string nit;

public:
    // ===================== M�TODOS CRUD =====================

    static void agregar(std::vector<Clientes>& lista, const std::string& usuarioActual);

    static void mostrar(const std::vector<Clientes>& lista);

    static void modificar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& idCliente);

    static void eliminar(std::vector<Clientes>& lista, const std::string& usuarioActual, const std::string& id);

    // ===================== M�TODOS DE ARCHIVO =====================

    static void guardarEnArchivo(const std::vector<Clientes>& listaClientes);

    static void cargarDesdeArchivo(std::vector<Clientes>& lista);

    // ===================== M�TODOS DE GESTI�N DE ID =====================

    static std::string generarIdUnico(const std::vector<Clientes>& lista);

    static bool idDisponible(const std::vector<Clientes>& lista, const std::string& id);

    static bool esIdValido(const std::string& id);

    // ===================== GETTERS =====================

    std::string getId() const { return id; }
    std::string getNombre() const { return nombre; }
    std::string getDireccion() const { return direccion; }
    std::string getTelefono() const { return telefono; }
    std::string getNit() const { return nit; }
};

#endif // CLIENTES_H
