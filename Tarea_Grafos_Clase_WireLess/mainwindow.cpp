#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->AreaRender = new RenderArea();

    // Crea la red interna, con 6 nodos, con 5 de alcance
    // y los nodos se generan entre 600 a 500 (area )

    this->W = new WireLess(100,50,730,470);


    // Al AreaRender siempre pasarle de parametro solo el grafo y no todo
    // Wireless para no modificar lo que ya se tenia
    this->AreaRender->setGrafo(W->grafo);

    this->ui->gridLayout->addWidget(this->AreaRender,0,0,1,1);

    this->CargarTabladeGrafo();
    ui->lblnota->setHidden(true);

}


MainWindow::~MainWindow()
{
    delete ui;
    delete this->AreaRender;
    delete this->W;
}

void MainWindow::on_pbAddArista_clicked()
{
    this->W->grafo->addArista(ui->leInicio->text().toInt(),
                           ui->leFinal->text().toInt(),
                           ui->lePeso->text().toFloat());

    this->AreaRender->update();
}

void MainWindow::Floyd()
{
    this->A = new float*[this->W->grafo->getSize()];
    for (int i=0; i<this->W->grafo->getSize();i++)
        this->A[i] = new float[this->W->grafo->getSize()];

    //Copiar la matriz del grafo en A (copia)
    for (int i=0;i<this->W->grafo->getSize();i++)
    {
        for (int j=0; j<this->W->grafo->getSize();j++)
            A[i][j] = this->W->grafo->getPesoArista(i,j);

    }
    // Algoritmo de Floyd
    for (int k =0; k<W->grafo->getSize();k++)
        for (int i =0; i<W->grafo->getSize();i++)
            for (int j =0; j<W->grafo->getSize();j++)
            {
               float peso = A[i][k] + A[k][j];
               if(peso < Grafo::INFINITO)
                   if (peso < A[i][j])
                       A[i][j] = peso ;


             }


    this->CargarTablaFloyd();


}
void MainWindow::CargarTabladeGrafo()
{
    this->ui->tableWidget->setRowCount(this->W->grafo->getSize());
    this->ui->tableWidget->setColumnCount(this->W->grafo->getSize());
    // QTableWidgetItem *item = new QTableWidgetItem("X");

    for (int i=0;i<this->W->grafo->getSize();i++)
    {
        for (int j=0; j<this->W->grafo->getSize();j++)
        {
            QString dato; dato.setNum(W->grafo->getPesoArista(i,j));
            QTableWidgetItem *item = new QTableWidgetItem(dato);
            this->ui->tableWidget->setItem(i,j,item);
        }
    }
    for(int i=0;i<W->grafo->getSize();i++)
    {
     QString temp;
     temp.setNum(i);
     ui->tableWidget->setHorizontalHeaderItem(i, new QTableWidgetItem(temp));
     ui->tableWidget->setVerticalHeaderItem(i, new QTableWidgetItem(temp));
    }
 }




void MainWindow::CargarTablaFloyd()
{
    this->ui->tableWidget->setRowCount(this->W->grafo->getSize());
    this->ui->tableWidget->setColumnCount(this->W->grafo->getSize());

    for (int i=0;i<this->W->grafo->getSize();i++)
    {
        for (int j=0; j<this->W->grafo->getSize();j++)
        {
            QString dato; dato.setNum(A[i][j]);
            QTableWidgetItem *item = new QTableWidgetItem(dato);
            this->ui->tableWidget->setItem(i,j,item);
        }
    }

}


void MainWindow::on_pushButton_clicked()
{
    this->Floyd();
}

void MainWindow::on_btn_recorrer_clicked()
{
    ui->lista_recorrido->clear();
    this->W->recorrer_en_profundidad(ui->sp_nodo->text().toInt());
    QColor col;
    col.setRgb(255,255,255,255);
    for(int i=0;i<this->W->lista_encontrados.count();i++){
            QListWidgetItem *it = new QListWidgetItem;
        if(!this->W->lista_encontrados.at(i).compare("===")){
            QColor tmp;
            tmp = this->setcol(rand()%8+1);
            while(col==tmp){
            tmp = this->setcol(rand()%8+1);
            }
            col = tmp;
            it->setBackgroundColor(col);
        }
        it->setBackgroundColor(col);
        it->setText(this->W->lista_encontrados.at(i));
        ui->lista_recorrido->addItem(it);
    }
    ui->lblnota->setHidden(false);
}

QColor MainWindow::setcol(int num){
    switch (num){
    case 1:
        return Qt::red;
        break;
    case 2:
        return Qt::blue;
        break;
    case 3:
        return Qt::green;
        break;
    case 4:
        return Qt::cyan;
        break;
    case 5:
        return Qt::magenta;

       break;
    case 6:
       return Qt::yellow;
    case 7:
       return Qt::darkGreen;
break;
    default :
            return Qt::white;
    break;
    }
}
