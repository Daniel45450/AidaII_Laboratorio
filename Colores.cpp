
#include <set>
#include <iostream>

using namespace std;

struct Color {
    int r=0;
    int g=0;
    int b=0;
};

bool operator<(const Color& color_a, const Color& color_b)
{
    if (color_a.r != color_b.r) {
        return color_a.r < color_b.r;
    }
    else if (color_a.g != color_b.g) {
        return color_a.g < color_b.g;
    }
    else {
        return color_a.b < color_b.b;
    }
}

void cargar_colores(set<Color> & colores)
{
    int cantidad_colores;
    cout << "Ingrese la cantidad de colores: ";
    cin >> cantidad_colores;
    cout << "Se van a generar " << cantidad_colores << " de forma aleatoria (incluyendo el rojo)" << endl;

    Color a;
    a.r = 255;
    a.g=0;
    a.b=0;
    colores.insert(a);
    for(int i=1; i< cantidad_colores; i++)
    {
        Color c;
        c.r = rand() % 255;
        c.g = rand() % 255;
        c.b = rand() % 255;
    }

}
