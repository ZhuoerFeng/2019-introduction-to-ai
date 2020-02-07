#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QMainWindow>

namespace Ui {
class UdpServer;
}

class UdpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit UdpServer(QWidget *parent = nullptr);
    ~UdpServer();

private:
    Ui::UdpServer *ui;
};

#endif // UDPSERVER_H
