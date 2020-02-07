#include "setinerval.h"
#include "ui_setinerval.h"

SetInerval::SetInerval(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetInerval)
{
    ui->setupUi(this);
}

SetInerval::~SetInerval()
{
    delete ui;
}
