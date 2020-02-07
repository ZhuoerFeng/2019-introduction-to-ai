#include "udpserver.h"
#include "ui_udpserver.h"

UdpServer::UdpServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UdpServer)
{
    ui->setupUi(this);
}

UdpServer::~UdpServer()
{
    delete ui;
}
