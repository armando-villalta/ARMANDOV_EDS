#ifndef GRAFO_H
#define GRAFO_H
#include <QString>
#include <QDebug>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <list>

using namespace std;

class nodo {
    public:

       int x,y;         // Posiciones en pantalla de texto
       QString etiqueta; // Solo para efectos de nombrar con una letra un nodo
       nodo() {x=0; y=0; etiqueta=""; }
};

class nodoVecino
{
public:
    nodo n;    // el nodo vecino
    float peso;  // Y la distancia en peso hacia ese nodo

};

class Grafo
{
  private:
    float **matriz;
    nodo *nodos;
    int _tamano;
    bool _dirigido;
    bool checkColision(int limite,int candidato_x,int candidato_y);
 public:
  Grafo(int cantidad_nodos,bool dirigido);
  void addArista(int nodo1, int nodo2, float peso);
  void removeArista(int nodo1, int nodo2);
  nodo getNodo(int i) ;
  float getPesoArista(int nodo1, int nodo2);
  void setPesoArista(int nodo1, int nodo2,float peso) ;
  void setEtiquetaNodo(int nodo1,string etiqueta);
  void setXYNodo(int nodo1, int x, int y);
  void generarPosicionesRandom(int ancho,int alto);
  void calcularDistancias() ; //Genera todas las distancias de acuerdo a pos x,y
  bool esDirigido() { return _dirigido ;}
  // TODO - implementar
  //bool hayArista(int nodo1, int nodo2);
  //int gradoDelNodo(int nodo);  // cuantas aristas salen de el
  //list<nodoVecino> getNodosVecinos(int nodo);
  //int getCantidadAristas(); // Regresa cuantas aristas tiene el grafo

  int getSize() { return _tamano; } // Regresa cuantos Nodos

   ~Grafo();

  static const float INFINITO = 99999.00;
  static const float DELTACOLISION = 25.0;
  static const int INTENTOS_COLISION =2;
  static float distancia(nodo A, nodo B)
  {
    return (sqrt( (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y) ));
  }
  static float distancia(int x1,int y1, int x2,int y2)
  {
    return (sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ));
  }

};

#endif // GRAFO_H
