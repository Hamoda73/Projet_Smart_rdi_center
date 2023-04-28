QT       += core gui sql charts
QT       += printsupport
QT       += core network
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    employe.cpp \
    employes.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    arduino.h \
    connection.h \
    employe.h \
    employes.h \
    mainwindow.h

FORMS += \
    employes.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    backg 2.jpg \
    backg 2.jpg \
    backg 2.jpg \
    backg 2.jpg \
    rsz back2.jpg
