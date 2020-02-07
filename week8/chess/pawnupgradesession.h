#ifndef PAWNUPGRADESESSION_H
#define PAWNUPGRADESESSION_H

#include <QDialog>

namespace Ui {
class PawnUpgradeSession;
}

class PawnUpgradeSession : public QDialog
{
    Q_OBJECT

public:
    explicit PawnUpgradeSession(QWidget *parent = nullptr);
    ~PawnUpgradeSession();

private:
    Ui::PawnUpgradeSession *ui;
};

#endif // PAWNUPGRADESESSION_H
