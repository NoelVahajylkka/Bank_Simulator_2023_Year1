QT       += core gui
QT +=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.



win32: LIBS += -L$$PWD/KirjautumisDLL/build/debug/ -lKirjautumisDLL

INCLUDEPATH += $$PWD/KirjautumisDLL
DEPENDPATH += $$PWD/KirjautumisDLL

win32: LIBS += -L$$PWD/DLLTalletus/build/debug/ -lTalletusDLL

INCLUDEPATH += $$PWD/DLLTalletus
DEPENDPATH += $$PWD/DLLTalletus

win32: LIBS += -L$$PWD/NostoTalletusDLL/build/debug/ -lNostoTalletusDLL

INCLUDEPATH += $$PWD/NostoTalletusDLL
DEPENDPATH += $$PWD/NostoTalletusDLL

win32: LIBS += -L$$PWD/nostoTalletusHistoriaDLL/build/debug/ -lnostoTalletusHistoriaDLL

INCLUDEPATH += $$PWD/nostoTalletusHistoriaDLL
DEPENDPATH += $$PWD/nostoTalletusHistoriaDLL

win32: LIBS += -L$$PWD/rfidDLL/build/debug/ -lrfidDLL

INCLUDEPATH += $$PWD/rfidDLL
DEPENDPATH += $$PWD/rfidDLL

win32: LIBS += -L$$PWD/TiliDLL/build/debug/ -lTiliDLL

INCLUDEPATH += $$PWD/TiliDLL
DEPENDPATH += $$PWD/TiliDLL
