QT       += core gui sql
QT += network

QT += printsupport
QT += sql

QT += core gui printsupport



LIBS += -LC:\Users\mdkhe\OneDrive\Documents\materiel\OpenSSL-Win64\lib
LIBS += -lssl -lcrypto

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    connection.cpp \
    emailsender.cpp \
    equipement.cpp \
    main.cpp \
    mainwindow.cpp \
    materiel.cpp


HEADERS += \
    connection.h \
    emailsender.h \
    equipement.h \
    mainwindow.h \
    materiel.h







FORMS += \
    mainwindow.ui \
    materiel.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourceee.qrc \
    resource.qrc \
    rsrc.qrc
