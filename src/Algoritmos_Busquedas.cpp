#include "Algoritmos_Busquedas.h"
#include <iostream>
using namespace std;

bool buscar_camino(const Grafo<int> & grafo, int origen, int destino, const Color & restriccion, const map<int, Color> & mapeo_colores, set<int> & visitados, list<int> & camino) //O(klog(n))
{
    visitados.insert(origen); //O(1)
    camino.push_back(origen); //O(1)
    if(origen == destino) {
        return true;
    }
    list<typename Grafo<int>::Arco> adyacentes;
    grafo.devolver_adyacentes(origen, adyacentes); //O(n) n = cantidad de vertices del grafo
    typename list<typename Grafo<int>::Arco>::const_iterator it_A = adyacentes.begin();
    while(it_A != adyacentes.end()) //itera O(k) k= promedio de vertices adyacentes
    {
        int adyacente = it_A->devolver_adyacente(); //O(1)
        if(visitados.find(adyacente) == visitados.end() && mapeo_colores.find(adyacente)->second != restriccion) //O(log(n)) dos find y Color se compara en O(1)
        {
            if(buscar_camino(grafo, adyacente, destino, restriccion, mapeo_colores, visitados, camino)) {
                return true;
            }
        }
        it_A++;
    }
    camino.pop_back(); //O(1)
    return false;
}
