#ifndef CREATESERVER_H
#define CREATESERVER_H

#include <QDialog>

namespace Ui {
class CreateServer;
}

class CreateServer : public QDialog
{
    Q_OBJECT

public:
    explicit CreateServer(QWidget *parent = nullptr);
    ~CreateServer();

private:
    Ui::CreateServer *ui;
};

#endif // CREATESERVER_H
