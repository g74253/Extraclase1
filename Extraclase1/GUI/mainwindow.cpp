#include "mainwindow.h"
#include "ui_mainwindow.h"

/// MainWindow: inicializa la interfaz
/// \param parent
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
/// ~MainWindow: destructor de la interfaz
MainWindow::~MainWindow()
{
    delete ui;
}

/// on_pushButton_clicked: accion de oprimir boton
void MainWindow::on_pushButton_clicked()
{
    int inicio = ui->spinBox->value();
    int fin = ui->spinBox_2->value();
    cliente sockets;
    string srt = sockets.enviar(to_string(inicio), to_string(fin));
    QString path = QString::fromStdString(srt);
    ui->label_3->setText(path);
}
