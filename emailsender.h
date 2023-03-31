#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include <QObject>
#include <QTcpSocket>
#include <QSslSocket>
#include <QTextStream>
#include <QList>
#include <QtNetwork>

class EmailSender : public QObject
{
    Q_OBJECT
public:
    explicit EmailSender(QObject *parent = nullptr);

    void sendEmail(const QString &user, const QString &password,
                   const QString &from, const QString &to,
                   const QString &subject, const QString &message);

private:
    void sendCommand(QSslSocket *socket, const QString &command);
    void handleSslErrors(const QList<QSslError> &errors);

    QSslSocket *socket;
};

#endif // EMAILSENDER_H
