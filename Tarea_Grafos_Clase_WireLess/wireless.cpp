#include "wireless.h"
#include <QMessageBox>
#include  <QList>
WireLess::WireLess()
{
    alcance=500.0;
    this->grafo = new Grafo(10,false);
    this->grafo->generarPosicionesRandom(300,300);
    this->grafo->calcularDistancias();
    this->removeAristasMayoresAlcance();
    this->visitados = new bool[10];
    this->tabladistancias = new QList<int>[10];

}

WireLess::WireLess(int nodos, float alcance,int ancho, int alto)
{
    this->alcance = alcance;
    this->grafo = new Grafo(nodos,false);
    this->grafo->generarPosicionesRandom(ancho,alto);
    //Esto calcula las distancias entre todo par de nodos
    this->grafo->calcularDistancias();
    // Sin embargo para efectos de la red inlambrica debemos
    // quitar todas aquellas aristas cuyo peso sea mayor al del alcance.
    this->removeAristasMayoresAlcance();
    this->visitados = new bool[nodos];
    this->tabladistancias = new QList<int>[nodos];
}

void WireLess::removeAristasMayoresAlcance()
{
    for (int i=0; i<this->grafo->getSize();i++)
    {
        for(int j=0; j<this->grafo->getSize();j++)
        {
            if (i!=j) // no son el mismo nodo
            {
              if(this->grafo->getPesoArista(i,j)> this->alcance)
                  this->grafo->removeArista(i,j);

            }

        }

    }
}


void WireLess::recorrer_en_profundidad(int n){
    this->tabladistancias->clear();
    this->lista_encontrados.clear();
    //SETEAR LOS VISITADOS EN FALSE DE TODOS
    for(int i=0;i<this->grafo->getSize();i++){
        this->visitados[i] = false;
    }
    //FIN SETEAR VISITADOS

//TABLA DE DISTANCIAS PARA SABER QUE NODOS ESTAND UNIDOS ENTRE SI
    for(int i=0;i<this->grafo->getSize();i++){
    for (int j=0;j<this->grafo->getSize();j++){
        if(this->grafo->distancia(this->grafo->getNodo(i),this->grafo->getNodo(j))<this->getAlcance()){
            this->tabladistancias[i].append(j);
    }
    }
}
    for (int i=0;i<this->tabladistancias->count();i++){
        for (int j=0;j<this->tabladistancias[i].count();j++){

        }

    }
//FIN TABLA DE DISTANCIAS NODOS

    //INICIO DE FUNCIO RP
    if(n<this->grafo->getSize()){
    this->rp(n);
    this->lista_encontrados.append("===");// SOLO PARA SEPARAR LAS DIVISIONES DENTOR DEL LOS NODOS NO UNIDOS
    for(int i=0;i<this->grafo->getSize();i++){
        if(!this->visitados[i]){
            this->rp(i);
            this->lista_encontrados.append("===");// SOLO PARA SEPARAR LAS DIVISIONES DENTOR DEL LOS NODOS NO UNIDOS
        }
    }
}else{
    //POR SI SE INGRESA UN NUMERO MAYOR AL DEL GRAFO!
    QMessageBox *box = new QMessageBox;
    QMessageBox::warning(box,"Error","Porfavor ingrese un valor menor o igual a "+QString::number(this->grafo->getSize()-1));
}

//FIN DE RP
}

void WireLess::rp(int n){
this->visitados[n] = true;
this->lista_encontrados.append(QString::number(n));
for (int i=0;i<this->tabladistancias[n].count();i++){
    if(!this->visitados[this->tabladistancias[n].at(i)]){
    this->rp(this->tabladistancias[n].at(i));
    }
}
}
