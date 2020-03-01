#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grafo.iniciar();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int w = ui->spinBox->value();
    int x = ui->spinBox_2->value();
    string srt = grafo.ruta(w, x);
    cliente g;
    g.enviar("hola");
    QString path = QString::fromStdString(srt);
    ui->label_3->setText(path);
}
