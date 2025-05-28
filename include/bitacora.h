#ifndef BITACORA_H
#define BITACORA_H
#include <string>
#include <unordered_map>

struct RegistroBitacora {
    int id_accion;
    int codigo;
    char usuario[50];
    char modulo[30];
    char descripcion[100];
    char fecha_hora[20];
};

class CodigosBitacora {
private:
    static std::unordered_map<std::string, int> rangos;

public:
    static int getCodigo(const std::string& modulo);
};

class bitacora {
public:

    static void registrar(const std::string& usuario, const std::string& modulo, const std::string& descripcion);

    static void insertar(const std::string& usuario, const std::string& modulo, const std::string& descripcion);

    static void mostrarBitacora();

    static void generarBackup();

    static void reiniciarBitacora();

    static void buscarPorNombreUsuario();

    static void buscarPorFecha();

    static void menuBitacora();

private:

    static std::string obtenerFechaActual();

};
#endif // BITACORA_H
