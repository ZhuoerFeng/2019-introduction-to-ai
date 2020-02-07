#ifndef CREATECLIENT_H
#define CREATECLIENT_H

#include <QDialog>

namespace Ui {
class CreateClient;
}

class CreateClient : public QDialog
{
    Q_OBJECT

public:
    explicit CreateClient(QWidget *parent = nullptr);
    ~CreateClient();

private:
    Ui::CreateClient *ui;
};

#endif // CREATECLIENT_H
