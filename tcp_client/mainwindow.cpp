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
    QObject::connect(ui->pushButton_3,&QPushButton::clicked,this,&MainWindow::slot_for_send_data);
    QObject::connect(tcp_client,&QTcpSocket::readyRead,this,&MainWindow::slot_for_receive_data);
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

void MainWindow::slot_for_send_data(){
    char* dt = "hello";
    qDebug() <<  QString::number(tcp_client->write(dt,sizeof(dt)));
    if(tcp_client->waitForBytesWritten(100)){
        qDebug() << "client write finally";
    }
}

void MainWindow::slot_for_receive_data(){
    QByteArray read_data = tcp_client->readAll();
    QString strData(read_data);
    ui->textBrowser->setText(strData);
}
