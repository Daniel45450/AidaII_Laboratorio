#include "Grafo.h"


//Clase Arco()

template <typename C>Grafo<C>::Arco::Arco() //O(1)
{

}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo) //O(r)
{
    this->costo = costo; //O(r) r: complejidad de costo para copiarse ya que es un tipo generico
    this->vertice = adyacente; //O(1)
}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const //O(1)
{
    return this->vertice; //El adyacente es un entero accesible en O(1)
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const //O(1)
{
    return this->costo; //O(1) ya que solo devuelve la direccion de memoria de costo
}

template <typename C> void Grafo<C>::Arco::modificar_costo(const C & costo)
{
    this->costo = costo; //O(r) r: complejidad de costo para copiarse ya que es un tipo generico
}

//Clase Grafo()


template <typename C> Grafo<C>:: Grafo() //O(1)

{
    //ctor
}

template <typename C> Grafo<C>::Grafo(bool dirigido) //O(1)
{
    this->dirigido = dirigido; //O(1)
}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{
    *this = otroGrafo;
}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)//O(nkr)
{
    this->vaciar(); //Lo vacio ya que si tiene contenido no sera igual al otro grafo O(n,k) n:cantidad de vertices, k= cantidad promedio de arcos(adyacentes) por vertice
    list<int> vertices; //O(1)
    otroGrafo.devolver_vertices(vertices); //O(n)
    list<int>::iterator itV = vertices.begin(); //O(1)
    while(itV != vertices.end()) { //itera O(n) veces pero tiene cosas adentro -> O(nkr)
        this->agregar_vertice(*itV); //O(1)
        list<Arco> adyacentes; //O(1)
        otroGrafo.devolver_adyacentes(*itV, adyacentes); //O(log(n))
        typename list<Arco>::iterator itA = adyacentes.begin(); //O(1)
        while(itA != adyacentes.end()) { //O(k)                                               r: complejidad de costo para copiarse ya que es un tipo generico
            this->agregar_arco(*itV, itA->devolver_adyacente(), itA->devolver_costo()); //devolver_adyacente y costo son O(1), pero agregar arco //O(Max(log(n), r))
            itA++;
        }
        itV++;
    }
    return *this;
}


template <typename C> Grafo<C>:: ~Grafo() //O(nkr)
{
    //dtor //Mismo analisis que para .vaciar O(nkr)
}

template <typename C> bool Grafo<C>::esta_vacio() const //O(1)
{
    return this->grafo.empty(); //O(1)
}

template <typename C> int Grafo<C>::devolver_longitud() const //O(1)
{
    return this->grafo.size(); //O(1)
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const //O(log(n)
{
    typename map<int, list<Arco>>::const_iterator it = this->grafo.find(vertice); // busco vertice -> O(log(n) n= cantidad_vertices;
    if(it != this->grafo.end()) return true; //O(1)
    return false;//O(1)
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const //O(Max(log(n),k))
{
    typename map<int, list<Arco>>::const_iterator itV = this->grafo.find(origen); // busco vertice -> O(log(n) n= cantidad_vertices;
    if(itV != this->grafo.end()) { //O(1)
        typename list<Arco>::const_iterator itA= itV->second.begin(); //O(1)
        while(itA != itV->second.end()) { //O(k) k= cantidad promedio de arcos(adyacentes) por vertice
            if(itA->devolver_adyacente() == destino) return true; //O(1)
            itA++;
        }
    }
    return false;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const //O(max(log(n), kr))
{
   typename map<int, list<Arco>>::const_iterator itV = this->grafo.find(origen); // busco vertice -> O(log(n) n= cantidad_vertices;
   typename list<Arco>::const_iterator itA = itV->second.begin(); //O(1)
   while(itA != itV->second.end()) { //Itera O(k) pero tiene devolver_costo -> O(kr) k= cantidad promedio de arcos(adyacentes) por vertice  r: complejidad de costo para copiarse ya que es un tipo generico
    if(itA->devolver_adyacente() == destino) return itA->devolver_costo();
    itA++;
   }
}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const //O(n) n= cantidad_vertices;
{
    typename map<int, list<Arco>>::const_iterator itV = this->grafo.begin(); //O(1)
    while(itV != this->grafo.end()) { //O(n) itero por todos los vertices.
        vertices.push_back(itV->first); //O(1)
        itV++;
    }
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const //O(log(n))
{
    typename map<int, list<Arco>>::const_iterator itV = this->grafo.find(origen); //busco el vertice origen //O(log(n)) n= cantidad_vertices;
    adyacentes = itV->second; //Asigno la referencia de memoria -> O(1)
}

template <typename C> void Grafo<C>::agregar_vertice(int vertice) //O(1)
{
    this->grafo.insert({vertice, list<Arco>{}}); //O(1): Creo un par y simplemente lo agrego si usara iteradores para el insert seria O(log(n)) n= cantidad_vertices;
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice) //O(max(log(n), k))
{
    this->grafo.erase(vertice); //Destruyo una key del mapa sin  usar iterador O(log(n))  n= cantidad_vertices;
                                //value: tiene una lista de arcos que tambien se destruye O(k) k= cantidad promedio de arcos(adyacentes) por vertice
}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo) //O(max(log(n),k,r))
{
    typename map<int, list<Arco>>::iterator itV = this->grafo.find(origen); //Busco el vertice origen O(log(n)) n = cantidad_vertices;
    typename list<Arco>::iterator itA= itV->second.begin(); //O(1)
    while(itA->devolver_adyacente() != destino) //busco en toda la lista de Arcos(vertices adyacentes) de origen //O(k) k= cantidad promedio de arcos(adyacentes) por vertice
    {
        itA++;
    }
    itA->modificar_costo(costo); //O(r) r: complejidad de costo para copiarse ya que es un tipo generico
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo) //O(Max(log(n), r))
{
    typename map<int, list<Arco>>::iterator itV= this->grafo.find(origen); //Busco el vertice origen O(log(n)) n = cantidad_vertices;
    if(itV != this->grafo.end()) { //O(1)
        Arco a1(destino, costo); //O(r) r: complejidad de costo para copiarse ya que es un tipo generico
        itV->second.push_back(a1); //Agrego al final de la lista de Arcos O(1)
    }
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino) //O(max(k, log(n)))
{
    typename map<int, list<Arco>>::iterator itV = this->grafo.find(origen); //Busco el vertice origen O(log(n)) n = cantidad_vertices;
    typename list<Arco>::iterator itA = itV->second.begin();
    while(itA->devolver_adyacente() != destino) { //busco en toda la lista de Arcos(vertices adyacentes) de origen //O(k) k= cantidad promedio de arcos(adyacentes) por vertice
        itA++;
    }
    itV->second.erase(itA); //O(k)
}

template <typename C> void Grafo<C>::vaciar() //O(nkr)
{
    this->grafo.clear(); //Destruyo todas  las key del mapa O(n)  n= cantidad_vertices; r: complejidad de costo para eliminarse ya que es un tipo generico
                        //value: tiene una lista de arcos que tambien se destruye O(kr) k= cantidad promedio de arcos(adyacentes) por vertice
}

template class Grafo<int>;
