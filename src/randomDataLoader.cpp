#include "randomDataLoader.h"
#include <cctype>


template <typename T, typename C> randomDataLoader<T,C>::randomDataLoader()
{
    //ctor
}

template <typename T, typename C> randomDataLoader<T,C>::~randomDataLoader()
{
    //dtor
}

template <typename T, typename C> void randomDataLoader<T,C>::cargar_colores_aleatorio(Colores<C> & colores)
{
    int cantidad;
    cout << "Ingresa la cantidad de colores a cargar: ";
    cin >> cantidad;
    srand(time(nullptr)); //Semilla
    for(int i=0; i<cantidad; i++) {
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        Color c(r,g,b);
        colores.agregar_color(c);
        cout << "Se creo el color: " << r << " " << g << " "  << b << " id: " << colores.obtener_cantidad_colores()-1 << endl;
    }
}

template <typename T, typename C> void randomDataLoader<T,C>::cargar_grafo_aleatorio(Grafo<T> & grafo)
{
    int cant_vertices;
    cout << "----- GENERACION DE VERTICES -----" << endl;
    cout << "\n" << endl;
    cout << "Ingresa la cantidad de vertices a generar: ";
    cin >> cant_vertices;
    cout << "\n" << endl;
    srand(time(nullptr));
    int i=0;
    while(i<cant_vertices) {
        int generado = rand() % cant_vertices;
        if(!grafo.existe_vertice(generado)) {
            cout << "Vertice: " << generado << " generado !!!\n";
            grafo.agregar_vertice(generado);
            i++;
        }
    }
    cout << "\n" << endl;
    cout << "----- GENERACION DE ARCOS -----" << endl;
    cout << "tener en cuenta los vertices generados" << endl;
    cout << "\n" << endl;
    cout << "Ingresa la cantidad de arcos a generar: ";
    int arcos;
    cin >> arcos;
    for(int k =0; k<arcos; k++)
    {
        int a;
        int b;
        int c;
        cout << "Ingresa el vertice a:";
        cin >> a;
        cout << "Ingresa el vertice b:";
        cin >> b;
        cout << "Ingresa un costo(entero): ";
        cin >> c;
        grafo.agregar_arco(a, b, c);
        cout << "Se creo el arco: " << a << "->" << b;
        cout << "\n" << endl;
    }

    cout << "----- GENERACION DEL GRAFO FINALIZADA -----" << endl;
}

template <typename T, typename C> void randomDataLoader<T,C>::cargar(Grafo<T> & grafo, Colores<C> & colores, map<int, C> & mapeo_colores)
{
    this->cargar_grafo_aleatorio(grafo);
    this->cargar_colores_aleatorio(colores);
    list<int> vertices;
    grafo.devolver_vertices(vertices);
    list<int>::iterator it_V = vertices.begin();
    char aleatorio;
    cout << "Cargar colores de forma aleatoria? (y/n): ";
    cin >> aleatorio;
    srand(time(nullptr));
    int id;
    while(it_V != vertices.end())
    {
        if(toupper(aleatorio) == 'N') {
            cout << "\n";
            cout << "Ingresa el id del color para asignar al vertice: " << *it_V << " (no olvidar el id de la restriccion): ";
            cin >> id;
            it_V++;
        } else {
            id = rand() % colores.obtener_cantidad_colores();
            if(colores.existe_color(id)) {
                mapeo_colores.insert({*it_V, colores.buscar_color_posicion(id)});
                it_V++;
            }
        }
    }
}

template class randomDataLoader<int, Color>;
