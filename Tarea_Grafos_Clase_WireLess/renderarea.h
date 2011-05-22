#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QString>
#include "grafo.h"

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    void setGrafo(Grafo *G ) { this->G = G; }

private:
    Grafo *G;
    void dibujarNodo(nodo n,QPainter &P);
    void dibujarArista(nodo n1,nodo n2, float peso, QPainter &P);
protected:
   void paintEvent(QPaintEvent *event);

public slots:

signals:

};

#endif // RENDERAREA_H
