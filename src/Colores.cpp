#include "Colores.h"
#include "Color.h"

template <typename T> Colores<T>::Colores()
{
    //ctor
}

template <typename T> Colores<T>::~Colores()
{
    //dtor
}

template <typename T> int Colores<T>::buscar_color(const T & color) const //O(n)
{
    int i = 0;
    while (i < this->colores.size()) {
        if (this->colores[i] == color) {
            return i; // Devuelve la posición del color en el vector
        }
        i++;
    }
    return -1; // Si el color no está en el vector, devuelve -1
}

template <typename T> bool Colores<T>::existe_color(const T & color) const //O(n)
{
    for (typename vector<T>::const_iterator it = this->colores.begin(); it != this->colores.end(); ++it) { //O(n)
        if (*it == color) {
            return true;
        }
    }
    return false;
}

template <typename T> void Colores<T>::agregar_color(const T & color) //O(1)
{
    this->colores.push_back(color); //O(1)
}

template <typename T> int Colores<T>::eliminar_color(const T & color) //O(n^2)
{
    int eliminar = this->buscar_color(color); //O(n)
    if(eliminar != -1) {
        this->colores.erase(this->colores.begin() + eliminar); //O(n)
        return 1;
    } else {
        return 0;
    }
}

template <typename T> T Colores<T>::buscar_color_posicion(int n) const //busca un color dada una posicion y devuelve una copia del color O(1)
{
    return this->colores[n];
}

template <typename T> int Colores<T>::obtener_cantidad_colores() const  //O(1)
{
    return this->colores.size();
}

template <typename T> bool Colores<T>::existe_color(int n) const //O(1)
{
    return (n < this->colores.size());
}

template <typename T> void Colores<T>::vaciar() {
    this->colores.clear();
}

template class Colores<Color>;
template class Colores<int>;
