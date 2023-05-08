
#include <set>
#include <iostream>
#include "Color.h"

using namespace std;

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
