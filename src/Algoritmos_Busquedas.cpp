#include "Algoritmos_Busquedas.h"
#include <iostream>
using namespace std;

bool buscar_camino(const Grafo<int> & grafo, int origen, int destino, const Color & restriccion, const map<int, Color> & mapeo_colores, set<int> & visitados, list<int> & camino)
{
    visitados.insert(origen);
    camino.push_back(origen);
    if(origen == destino) {
        return true;
    }
    list<typename Grafo<int>::Arco> adyacentes;
    grafo.devolver_adyacentes(origen, adyacentes);
    typename list<typename Grafo<int>::Arco>::const_iterator it_A = adyacentes.begin();
    while(it_A != adyacentes.end())
    {
        int adyacente = it_A->devolver_adyacente();
        if(visitados.find(adyacente) == visitados.end() && mapeo_colores.find(adyacente)->second != restriccion)
        {
            if(buscar_camino(grafo, adyacente, destino, restriccion, mapeo_colores, visitados, camino)) {
                return true;
            }
        }
        it_A++;
    }
    visitados.erase(origen);
    camino.pop_back();
    return false;
}
