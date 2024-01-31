#include "tili.h"
#include "ui_tili.h"
#include <QDebug>
Tili::Tili(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Tili)
{

    ui->setupUi(this);
    ui->Huomautus->setVisible(false);
    setWindowTitle("Valikko");
    connect(ui->pushValinta, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerTilinValinta()));
    connect(ui->pushKirjauduUlos, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerKirjauduUlos()));
    connect(ui->pushHistoria, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerHistoria()));
    connect(ui->pushTalletusNosto, SIGNAL(clicked(bool)),
            this, SLOT(clickHandlerTalletus()));
    connect(ui->Push_Nosto, SIGNAL(clicked(bool)),this,SLOT(clickHandlerNosto()));
}

Tili::~Tili()
{
    delete ui;
}

void Tili::TiliNumSet()
{
    qDebug()<<"tilinumset";
    qDebug()<<Tilinum;
    ui->Lable_TiliNumero->setText(Tilinum);
    if(Debit==true){
        ui->Lable_Otsikko->setText("Debit");
    } else {
        ui->Lable_Otsikko->setText("Credit");
    }
}
void Tili::clickHandlerTilinValinta()
{
    qDebug()<<"Tilin valinta";
    qDebug()<<Valinta;
    if(Valinta==false){
    ui->Huomautus->setVisible(true);
    }else {
        emit creditDebit();
    }
}

void Tili::clickHandlerKirjauduUlos()
{
    qDebug()<<"KirjauduUlos";
    ui->Huomautus->setVisible(false);
    emit kirjauduUlos();
    this->deleteLater();
    this->close();
}

void Tili::clickHandlerNosto()
{
    qDebug()<<"Nosto";
     ui->Huomautus->setVisible(false);
    emit nosto();

}

void Tili::clickHandlerTalletus()
{
    qDebug()<<"Talletus";
     ui->Huomautus->setVisible(false);
    emit talletus();
}

void Tili::clickHandlerHistoria()
{
    qDebug()<<"Historia";
     ui->Huomautus->setVisible(false);
    emit historia();
}
