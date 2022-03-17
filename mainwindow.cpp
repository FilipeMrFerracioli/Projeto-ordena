#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonGerar_clicked()
{
    try {
        ordena = new minhaNamespace::Ordena(ui->lineEditTamanhoVetor->text().toInt());

        ordena->gerarValoresEInserir();

        ui->lineEditVetorAleatorio->setText(ordena->getVetorAleatorio());
        //ui->lineEditVetorOrdenado->setText(ordena->getVetorOrdenado());
    }  catch (QString &erro) {
        QMessageBox::information(this, "Erro", erro);
    }
}

