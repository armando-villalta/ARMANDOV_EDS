#ifndef WIRELESS_H
#define WIRELESS_H
#include "grafo.h"
#include <QList>





class WireLess
{
public:
    WireLess(); // por default 10 nodos, y alcance de 5.0
    WireLess(int nodos, float alcance,int ancho, int alto);
    void setAlcance(float al) { alcance=al;}
    float getAlcance () { return alcance; }
    ~WireLess() { delete grafo;}   // Corre el destructor de grafo
    Grafo *grafo;
    void recorrer_en_profundidad(int n);
    QList<QString> lista_encontrados;
private:
    float alcance;
    void removeAristasMayoresAlcance();
    bool *visitados;
    void rp(int n);
    QList<int> *tabladistancias;



};

#endif // WIRELESS_H
