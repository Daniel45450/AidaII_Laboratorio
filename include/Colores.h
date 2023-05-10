#ifndef COLORES_H
#define COLORES_H

#include <vector>

using namespace std;

template <typename T> class Colores
{
    public:
        Colores();
        virtual ~Colores();
        void agregar_color(const T & color); //Agrega un color a la coleccion
        int eliminar_color(const T & color); //Elimina un color de la coleccion buscandolo previamente, retorna 1 si se elimino 0 si no se elimino.
        int buscar_color(const T & color) const; //busca un color en la coleccion y lo devuelve -1 si no esta y si esta su posicion
        T buscar_color_posicion(int n) const; //busca un color dada una posicion y devuelve una copia del color
        bool existe_color(const T & color) const; // verifica si esta agregado un color en la coleccion pasando un color
        bool existe_color(int n) const; //verifica si hay un color en una posicion determinada
        int obtener_cantidad_colores() const;

    private:
        vector<T> colores;
};

#endif // COLORES_H
