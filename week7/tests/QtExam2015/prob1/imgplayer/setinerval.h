#ifndef SETINERVAL_H
#define SETINERVAL_H

#include <QDialog>

namespace Ui {
class SetInerval;
}

class SetInerval : public QDialog
{
    Q_OBJECT

public:
    explicit SetInerval(QWidget *parent = nullptr);
    ~SetInerval();

private:
    Ui::SetInerval *ui;
};

#endif // SETINERVAL_H
