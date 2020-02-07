#include "updclient.h"
#include "ui_updclient.h"

UpdClient::UpdClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UpdClient)
{
    ui->setupUi(this);
}

UpdClient::~UpdClient()
{
    delete ui;
}
