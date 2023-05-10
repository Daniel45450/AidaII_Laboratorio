#include "Grafo.h"
#include "Color.h"
#include "iostream"
#include <set>
#include "randomDataLoader.h"

using namespace std;

template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	// Recorremos todos los vertices
	list<int> vertices;
	grafo.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << " (" << ady->devolver_costo() << ")\n";
			ady++;
		}
		v++;
	}
	return salida;
}

ostream & operator << (ostream & salida, const Color c)
{
	salida << "    " << c.obtener_RED() << " " << c.obtener_GREEN() << " " << c.obtener_BLUE();
	return salida;
}

template <typename T>  ostream & operator << (ostream & salida, const Colores<T> c)
{
    for(int i=0; i< c.obtener_cantidad_colores(); i++) {
        salida << "    " << c.buscar_color_posicion(i) << "\n";
    }

	return salida;
}


int main(int argc, char **argv)
{
	Grafo<int> g;
	/*

	// Cargamos un grafo dirigido
	// Primero los vértices
	g.agregar_vertice(1);
	g.agregar_vertice(2);
	g.agregar_vertice(3);
	g.agregar_vertice(4);
	g.agregar_vertice(5);
	g.agregar_vertice(6);
	g.agregar_vertice(7);
    g.agregar_vertice(8);

	// Luego los arcos
	g.agregar_arco(1, 2, 1);
	g.agregar_arco(1, 3, 1);
	g.agregar_arco(1, 4, 1);
	g.agregar_arco(2, 6, 2);
	g.agregar_arco(3, 5, 3);
	g.agregar_arco(4, 7, 4);
	g.agregar_arco(5, 6, 5);
	*/

	randomDataLoader<int, Color> loader;
	//loader.cargar_grafo_aleatorio(g);
	Colores<Color> c;
	loader.cargar_colores_aleatorio(c);
	cout << "Colores:\n" << c << "\n";

	// Mostramos el grafo
	//cout << "Estructura del grafo:\n" << g << "\n";

	int origen = 1;
	int destino = 6;

	//set<Color> colores;
	//cargar_colores(colores);

	//falta:
	//Asociar un color a todo los vertices
	//buscar_camino(origen, destino);


	return 0;
}

/*
void cargar_colores(set<Color> & colores)
{
    int cantidad_colores;
    cout << "Ingrese la cantidad de colores: ";
    cin >> cantidad_colores;
    cout << "Se van a generar " << cantidad_colores << " de forma aleatoria (incluyendo el rojo)" << endl;

    Color a(255,0,0);

    colores.insert(a);
    for(int i=1; i< cantidad_colores; i++)
    {

        int r = rand() % 255;
        int g = rand() % 255;
        int b = rand() % 255;
        Color c(r,g,b);
    }
}
*/
