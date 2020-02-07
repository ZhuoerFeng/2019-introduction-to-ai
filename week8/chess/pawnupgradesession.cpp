#include "pawnupgradesession.h"
#include "ui_pawnupgradesession.h"

PawnUpgradeSession::PawnUpgradeSession(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PawnUpgradeSession)
{
    ui->setupUi(this);
}

PawnUpgradeSession::~PawnUpgradeSession()
{
    delete ui;
}
