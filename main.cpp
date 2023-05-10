#include "Grafo.h"
#include "Color.h"
#include "iostream"
#include <set>
#include "randomDataLoader.h"
#include "Algoritmos_Busquedas.h"

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

ostream & operator << (ostream & salida, const Color &  c)
{
	salida << "    " << c.obtener_RED() << " " << c.obtener_GREEN() << " " << c.obtener_BLUE();
	return salida;
}

template <typename T>  ostream & operator << (ostream & salida, const Colores<T> & c)
{
    for(int i=0; i< c.obtener_cantidad_colores(); i++) {
        salida << "    " << c.buscar_color_posicion(i) << "\n";
    }

	return salida;
}

ostream & operator << (ostream & salida, const map<int,Color> & mapa)
{
    for(typename map<int, Color>::const_iterator it_m = mapa.begin(); it_m != mapa.end(); it_m++) {
        salida << "    " << it_m->first << " -> " << it_m->second << "\n";
    }
	return salida;
}

ostream & operator << (ostream & salida, const list<int> & lista)
{
    for(typename list<int>::const_iterator it_l = lista.begin(); it_l != lista.end(); it_l++) {
        salida << "    " << *it_l;
    }
	return salida;
}

int main(int argc, char **argv)
{
	Grafo<int> g;
    int opcion;
    Color restriccion;
    bool salir;
    Colores<Color> colores;
    map<int, Color> mapeo_colores;
    while(!salir) {
        cout << "-- Menu --\n" << endl;
        cout << "1) Cargar restriccion(rojo en rgb= 255, 0, 0)" << endl;
        cout << "2) Generar instancia" << endl;
        cout << "3) Buscar camino restringido" << endl;
        cout << "4) Salir\n" << endl;
        cout << "Ingresa una opcion " << endl;
        cin >> opcion;
        switch(opcion) {
            case 1:
            {
               int r;
               int g;
               int b;
               cout << "Ingresa el valor r: ";
               cin >> r;
               cout << "Ingresa el valor g: ";
               cin >> g;
               cout << "Ingresa el valor b: ";
               cin >> b;
               restriccion.modificar_color(r,g,b);
               colores.agregar_color(restriccion);
               cout << "Se agrego como restriccion el color: " << restriccion << " id: " << colores.obtener_cantidad_colores()-1 << "\n";
            }
            case 2: {
                randomDataLoader<int, Color> loader;
                loader.cargar(g, colores, mapeo_colores);
                cout << "Estructura del grafo:\n" << g << "\n" << "Colores creados(r,g,b):\n" << colores << "\n" << "Mapeo de colores:\n"<< mapeo_colores << endl;
            }
            case 3: {
                int origen;
                int destino;
                cout << "Ingresa el origen: ";
                cin >> origen;
                cout << "Ingresa el destino: ";
                cin >> destino;
                list<int> camino;
                set<int> visitados;
                buscar_camino(g, origen, destino, restriccion, mapeo_colores, visitados, camino);
                cout << "Camino:\n";
                cout << camino << "\n";
            }
            case 4: {
                salir = true;
            }
        }

    }
	return 0;
}
