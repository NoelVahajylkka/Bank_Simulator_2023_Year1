#include "TalletusDLL.h"
#include "ui_TalletusDLL.h"
#include <QDebug>
#include <chrono>
#include <thread>

Talletus::Talletus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Talletus)
{    
    qDebug()<<"DLL:n konstruktorissa";

    ui->setupUi(this);

    setWindowTitle("Talletus");

    validator = new QIntValidator(1, 9999, this);
    ui->textSumma->setValidator(validator);

    connect(ui->buttonEnter, SIGNAL(clicked()),
            this, SLOT(clickHandlerEnter()));
    connect(ui->peruutaButton, SIGNAL(clicked()),
            this, SLOT(clickHandlerEdellinen()));
}

Talletus::~Talletus()
{    
    qDebug()<<"DLL:n desktruktorissa";
    delete ui;
}

void Talletus::clickHandlerEnter()
{
    float debitSaldo, creditSaldo;
    qDebug()<<"Debitsaldo: " + DebitSaldo;
    qDebug()<<"Creditsald0 : " + CreditSaldo;
    qDebug()<<Debit;
    qDebug()<<"DLL:n clickHandlerEnter";

    debitSaldo = DebitSaldo.toFloat();
    creditSaldo = CreditSaldo.toFloat();
    qDebug()<<ui->textSumma->text().toFloat();
    lahetettavaLuku = ui->textSumma->text().toFloat();

    if(Debit == true) {
        emit lahetys(debitSaldo, lahetettavaLuku);
        ui->textSumma->clear();
        ui->label->setText("Talletus hyväksytty");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        ui->label->clear();
        ui->label->setText("Syötä summa");
        this->close();
    }

    else if(Debit == false) {
        emit lahetys(creditSaldo, lahetettavaLuku);
        ui->textSumma->clear();
        ui->label->setText("Talletus hyväksytty");
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        //ui->label->clear();
        ui->label->setText("Syötä summa");
        this->close();
    }
}

void Talletus::clickHandlerEdellinen()
{
    this->close();
}
