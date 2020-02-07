#include "createclient.h"
#include "ui_createclient.h"

CreateClient::CreateClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateClient)
{
    ui->setupUi(this);
}

CreateClient::~CreateClient()
{
    delete ui;
}
