#ifndef RANDOMDATALOADER_H
#define RANDOMDATALOADER_H

#include "Grafo.h"
#include "Color.h"
#include "Colores.h"
#include <iostream>
#include <ctime>

using namespace std;

template <typename T, typename C> class randomDataLoader
{
    public:
        randomDataLoader();
        virtual ~randomDataLoader();
        void cargar_grafo_aleatorio(Grafo<T> & grafo); //Carga un grafo
        void cargar_colores_aleatorio(Colores<C> & colores); //Carga un vector de colores
        //No se que nombre ponerle a esto asi que lo deje como cargar
        void cargar(Grafo<T> & grafo, Colores<T> & colores, map<int,Color> & mapeo_colores); //Carga el grafo, los colores y crea un mapeo que relaciona un vertice y un color;

};

#endif // RANDOMDATALOADER_H
