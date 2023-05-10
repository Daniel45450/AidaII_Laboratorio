#ifndef ALGORITMOS_BUSQUEDAS_H_INCLUDED
#define ALGORITMOS_BUSQUEDAS_H_INCLUDED

#include "Color.h"
#include <set>
#include "Colores.h"
#include "Grafo.h"

bool buscar_camino(const Grafo<int> & grafo, int origen, int destino, const Color & restriccion, const map<int,Color> & mapeo_colores, set<int> & visitados, list<int> & Camino);

#endif // ALGORITMOS_BUSQUEDAS_H_INCLUDED
