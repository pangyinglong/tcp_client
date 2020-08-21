#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTcpSocket* tcp_client;
private:
    Ui::MainWindow *ui;
public slots:
    void slot_for_tcp_client_connect();
    void slot_for_send_data();
    void slot_for_receive_data();
};

#endif // MAINWINDOW_H
