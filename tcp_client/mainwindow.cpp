#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tcp_client = new QTcpSocket(this);
    QObject::connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::slot_for_tcp_client_connect);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_for_tcp_client_connect(){
    if(tcp_client){
        tcp_client->connectToHost(ui->serverIP->text(),ui->port->text().toInt());
        if(tcp_client->waitForConnected(1000)){
               qDebug() << "client connect";
        }
    }
}
