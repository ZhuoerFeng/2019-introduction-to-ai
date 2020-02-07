#include "createserver.h"
#include "ui_createserver.h"

CreateServer::CreateServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateServer)
{
    ui->setupUi(this);
}

CreateServer::~CreateServer()
{
    delete ui;
}
