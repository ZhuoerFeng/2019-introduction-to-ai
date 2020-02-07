#ifndef UPDCLIENT_H
#define UPDCLIENT_H

#include <QMainWindow>

namespace Ui {
class UpdClient;
}

class UpdClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit UpdClient(QWidget *parent = nullptr);
    ~UpdClient();

private:
    Ui::UpdClient *ui;
};

#endif // UPDCLIENT_H
