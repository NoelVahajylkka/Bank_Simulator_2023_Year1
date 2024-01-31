/********************************************************************************
** Form generated from reading UI file 'rfid.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RFID_H
#define UI_RFID_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rfid
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;

    void setupUi(QDialog *rfid)
    {
        if (rfid->objectName().isEmpty())
            rfid->setObjectName("rfid");
        rfid->resize(221, 181);
        verticalLayoutWidget = new QWidget(rfid);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 70, 71, 51));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        verticalLayout->addWidget(label);

        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setMaximumSize(QSize(0, 0));
        lineEdit->setFrame(true);

        verticalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(0, 0));

        verticalLayout->addWidget(pushButton);


        retranslateUi(rfid);

        QMetaObject::connectSlotsByName(rfid);
    } // setupUi

    void retranslateUi(QDialog *rfid)
    {
        rfid->setWindowTitle(QCoreApplication::translate("rfid", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("rfid", "N\303\244yt\303\244 kortti", nullptr));
        pushButton->setText(QCoreApplication::translate("rfid", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class rfid: public Ui_rfid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RFID_H
