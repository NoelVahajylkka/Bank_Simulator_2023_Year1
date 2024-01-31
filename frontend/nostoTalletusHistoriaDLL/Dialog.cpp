#include "Dialog.h"
#include "ui_Dialog.h"
#include "environment.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    //Tehdään connectit
    ui->setupUi(this);
    connect(ui->edellinen,SIGNAL(clicked(bool)),this,SLOT(edellinenHandler()));
    connect(ui->seuraava,SIGNAL(clicked(bool)),this,SLOT(seuraavaHandler()));
    connect(ui->takaisin,SIGNAL(clicked(bool)),this,SLOT(takaisinHandler()));
    qDebug()<<"TiliID:";
    qDebug()<<TiliID;
    qDebug()<<"token:";
    qDebug()<<token;
    qDebug()<<"history";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::edellinenHandler()
{
    qDebug()<<"edellinen";
    if(Offset!=0){
    Offset = Offset-5;
    } else {
        qDebug()<<"Offset 0";
    }
    getHistory();

}

void Dialog::seuraavaHandler()
{
    qDebug()<<"seuraava";
    qDebug()<<Toisto;
    if(maaracounter <5){
    qDebug()<<"Ei toisto";
    }
    else{
    Offset = Offset+5;
    }
    qDebug()<<Offset;
    getHistory();

}

void Dialog::takaisinHandler()
{
    qDebug()<<"takaisin";
    this->close();
    this->deleteLater();
}

void Dialog::getHistory()
{
    qDebug()<<"testi";
    QString OffsetT = QString::number(Offset);
    QString DebitT = QString::number(Debit);
    qDebug()<<OffsetT;
    qDebug()<<DebitT;
    qDebug()<<"TiliID"+TiliID;
    QString site_url=Environment::getBaseUrl()+"/nostoH/1/1/"+OffsetT;

    qDebug()<<site_url;
    //QString tili_url=getBaseURLTili() + databaseID,
    //asiakasTili_url = getBaseURLpvNostoRaja() + AsiakasID + "/" + databaseID;
    //qDebug()<<tili_url;
    //QNetworkRequest requestTili((tili_url)), requestAsiakasTili((asiakasTili_url));

    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(token));
    //WEBTOKEN LOPPU
    getHistoryManager = new QNetworkAccessManager(this);
    connect(getHistoryManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getHistorySlot(QNetworkReply*)));

    reply = getHistoryManager->get(request);
    qDebug()<<reply;
}
void Dialog::getHistorySlot(QNetworkReply*reply)
{    
    QByteArray response_data=reply->readAll();
         QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
         QJsonArray json_array = json_doc.array();
         QString vanhanostoID,idNostoHistoria,DATETIME,Debit,idTili,MAARA;
         foreach (const QJsonValue &value, json_array) {
           QJsonObject json_obj = value.toObject();
           idNostoHistoria+=QString::number(json_obj["idNostoHistoria"].toInt());
           DATETIME+=(json_obj["DATETIME"].toString())+",";
           MAARA+=QString::number(json_obj["MAARA"].toInt())+"€"+",";
           Debit+=QString::number(json_obj["Debit"].toInt());
           idTili+=QString::number(json_obj["idTili"].toInt());
         }

    /*qDebug()<<"nostoID: "+idNostoHistoria;
    qDebug()<<"aika: "+DATETIME;
    //qDebug()<<"maara: "+MAARA;
    qDebug()<<"debittest: "+Debit;
    qDebug()<<"tiliID: "+idTili;*/

    QStringList MAARA1 = MAARA.split(",");
    int maara = MAARA1.count();
    maaracounter = MAARA1.count();
    QStringList DATETIME1 = DATETIME.split(",");
    QString maara5;
    QString DATE5;
    maara=maara-1;
    qDebug()<<idNostoHistoria;
    if(idNostoHistoria != vanhanostoID){
    for(int x=0;x<5;x++){
                switch (x){
                case 0:
                    ui->aika1->setText("");
                    ui->maara1->setText("");
                    break;
                case 1:
                    ui->aika2->setText("");
                    ui->maara2->setText("");
                    break;
                case 2:
                    ui->aika3->setText("");
                    ui->maara3->setText("");
                    break;
                case 3:
                    ui->aika4->setText("");
                    ui->maara4->setText("");
                    break;
                case 4:
                    ui->aika5->setText("");
                    ui->maara5->setText("");
                    break;
              }
    }
    for(int x=0;x<maara;x++){
        switch (x){
        case 0:
            maara5 = MAARA1[x];
            ui->maara1->setText(maara5);
            break;
        case 1:
            maara5 = MAARA1[x];
            ui->maara2->setText(maara5);
            break;
        case 2:
            maara5 = MAARA1[x];
            ui->maara3->setText(maara5);
            break;
        case 3:
            maara5 = MAARA1[x];
            ui->maara4->setText(maara5);
            break;
        case 4:
            maara5 = MAARA1[x];
            ui->maara5->setText(maara5);
            break;
        }
    for(int x=0;x<maara;x++){
            switch (x){
            case 0:
                DATE5 = DATETIME1[x];
                ui->aika1->setText(DATE5);
                break;
            case 1:
                DATE5 = DATETIME1[x];
                ui->aika2->setText(DATE5);
                break;
            case 2:
                DATE5 = DATETIME1[x];
                ui->aika3->setText(DATE5);
                break;
            case 3:
                DATE5 = DATETIME1[x];
                ui->aika4->setText(DATE5);
                break;
            case 4:
                DATE5 = DATETIME1[x];
                ui->aika5->setText(DATE5);
                break;
            }

    }
 Toisto = false;
}
} else {
 qDebug()<<"toistoa";
 Toisto = true;
}
    qDebug()<<idNostoHistoria;
    qDebug()<<vanhanostoID;
    //ui->aika1->setText(DATETIME);
    //ui->maara1->setText(MAARA1[1]);
    reply->deleteLater();
    getHistoryManager->deleteLater();
}
