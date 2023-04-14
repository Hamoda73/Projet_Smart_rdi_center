#include "emailsender.h"

EmailSender::EmailSender( QObject *parent) : QObject(parent)

{
    // Create the SSL socket ( makes a secure connection with the smtp server )
    socket = new QSslSocket(this);

    // Connect signals to slots, establish a connection between signals and slots
    //here it connects the sslerrors signal of the socket object, to the handlesslerrors's slot
    connect(socket, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(handleSslErrors(QList<QSslError>)));
}



void EmailSender::sendEmail(const QString &user, const QString &password, const QString &from,
                             const QString &to , const QString &subject, const QString &message)


{
    // 1 Set up the socket
    socket->connectToHostEncrypted("smtp.gmail.com", 465);
    if(!socket->waitForConnected(5000)) {
        qDebug() << "Could not connect to host";
        return;
    }

    // 2 Send commands
    // Send the EHLO command ( identify the client )
    sendCommand(socket, "EHLO smtp.gmail.com");

    // Send the AUTH LOGIN command ( send the login creds )
    sendCommand(socket, "AUTH LOGIN");

    // Send the username to the server in  a base64-encoded format
    QByteArray userBase64 = user.toUtf8().toBase64();
    sendCommand(socket, userBase64);

    // Send the password to the server in  a base64-encoded format
    QByteArray passwordBase64 = password.toUtf8().toBase64();
    sendCommand(socket, passwordBase64);

    //After the authentication process is done
    //toUtf8 to encode

    // Send the MAIL FROM command
    sendCommand(socket, "MAIL FROM:<" + from.toUtf8() + ">");

    // Send the RCPT TO command
    sendCommand(socket, "RCPT TO:<" + to.toUtf8() + ">");

    // Send the DATA command
    sendCommand(socket, "DATA");

    // Send the message headers and body
    QTextStream stream(socket);
    stream << "From: " << from << "\r\n";
    stream << "To: " << to << "\r\n";
    stream << "Subject: " << subject << "\r\n";
    stream << "MIME-Version: 1.0\r\n";
    stream << "Content-Type: text/plain; charset=utf-8\r\n";
    stream << "Content-Transfer-Encoding: 8bit\r\n";
    stream << "\r\n";
    stream << message << "\r\n";
    stream << "." << "\r\n";
    stream.flush();
    // Send the QUIT command
    sendCommand(socket, "QUIT");
    // Wait for the connection to be closed
    socket->waitForDisconnected();
}

void EmailSender::sendCommand(QSslSocket *socket, const QString &command)
{
    QTextStream stream(socket);
    // sends the command to the server by writing it to a QTextStream object

    stream << command << "\r\n";
    stream.flush(); // To make sure its sent
    //2nd
    if(!socket->waitForReadyRead(5000)) {
        qDebug() << "Error sending command: " << command;
    }
    QString response = QString::fromUtf8(socket->readAll());
    qDebug() << command << " response: " << response;
}

void EmailSender::handleSslErrors(const QList<QSslError> &errors)
{
    foreach(QSslError error, errors) {
        qDebug() << "SSL Error: " << error.errorString();
    }
    socket->ignoreSslErrors();
}
