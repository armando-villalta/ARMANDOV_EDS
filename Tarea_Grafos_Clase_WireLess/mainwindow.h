#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTableWidgetItem>

#include "wireless.h"
#include "grafo.h"

#include "renderarea.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    RenderArea *AreaRender;
    WireLess *W;
    float **A;
    void CargarTabladeGrafo();
    void CargarTablaFloyd();
    void Floyd();
    QColor setcol(int n);
private slots:
    void on_btn_recorrer_clicked();
    void on_pushButton_clicked();
    void on_pbAddArista_clicked();
};

#endif // MAINWINDOW_H
