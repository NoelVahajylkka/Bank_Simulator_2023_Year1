#ifndef TILI_H
#define TILI_H
#include "TiliDLL_global.h"
#include <QDialog>

namespace Ui {
class Tili;
}

class TILIDLL_EXPORT Tili : public QDialog
{
    Q_OBJECT

public:
    explicit Tili(QWidget *parent = nullptr);
    ~Tili();
    QString Tilinum;
    bool Valinta,Debit;
    void TiliNumSet();
private slots:
    void clickHandlerTilinValinta();
    void clickHandlerKirjauduUlos();
    void clickHandlerNosto();
    void clickHandlerHistoria();
    void clickHandlerTalletus();
private:
    Ui::Tili *ui;
signals:
    void nosto();
    void talletus();
    void historia();
    void kirjauduUlos();
    void creditDebit();
};

#endif // TILI_H
