#include "rfid.h"
#include "ui_rfid.h"
#include <QDebug>

rfid::rfid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rfid)
{
    ui->setupUi(this);
    //Piilotetaan lineEditin teksti
    ui->lineEdit->setEchoMode(QLineEdit::NoEcho);
    //Yhdistetään näkymätön nappi clicHandleriin joka lähettää kortin numeron mainwindowille
    connect(ui->pushButton,SIGNAL(clicked(bool)),
            this, SLOT(clickHandler()));

    connect(&aika,SIGNAL(timeout()),
            this,SLOT(handleTimeout()));
    aika.start(10000);
}

rfid::~rfid()
{
    delete ui;
}

void rfid::clickHandler()
{
    QString luku = ui->lineEdit->text();
    emit sendCardNumber(luku);
    aika.stop();
}

void rfid::handleTimeout()
{
    qDebug()<<"RFID TimeOut";
    this->close();
    delete this;
}


