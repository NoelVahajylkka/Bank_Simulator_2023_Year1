#ifndef RFID_H
#define RFID_H
#include "rfidDLL_global.h"
#include <QDialog>
#include <QTimer>

namespace Ui {
class rfid;
}

class rfid : public QDialog
{
    Q_OBJECT

public:
    explicit rfid(QWidget *parent = nullptr);
    ~rfid();
signals:
    void sendCardNumber(QString);

private slots:
    void clickHandler();
    void handleTimeout();

private:
    Ui::rfid *ui;
    QTimer aika;
};

#endif // RFID_H
