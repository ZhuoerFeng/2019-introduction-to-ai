#ifndef INPUT_H
#define INPUT_H

#include <QDialog>

namespace Ui {
class Input;
}

class Input : public QDialog
{
    Q_OBJECT

public:
    explicit Input(QWidget *parent = nullptr);
    ~Input();

private:
    Ui::Input *ui;
};

#endif // INPUT_H
