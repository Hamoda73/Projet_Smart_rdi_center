#include "arduino.h"
#include <QDebug>

arduino::arduino()
{
    data="";
    arduino_prot_name="";
    arduino_is_available=false;
    serial = new QSerialPort;
}

QString arduino::getarduino_port_name()
{
    return arduino_prot_name;
}
QSerialPort * arduino::getserial()
{
    return serial;
}
int arduino::connect_arduino()
{
    foreach (const QSerialPortInfo &seria_port_info, QSerialPortInfo::availablePorts())
    {
        if (seria_port_info.hasVendorIdentifier() && seria_port_info.hasProductIdentifier())
        {
            if(seria_port_info.vendorIdentifier() == arduino_uno_vendor_id && seria_port_info.productIdentifier() == arduino_uno_product_id)
            {
                arduino_is_available = true;
                arduino_prot_name = seria_port_info.portName();
            }
        }
    }
    if (arduino_is_available)
    {
        serial->setPortName(arduino_prot_name);
        if(serial->open(QSerialPort::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int arduino::close_arduino()
{
    if (serial->isOpen())
    {
        serial->close();
        return 0;
    }
    return 1;
}

int arduino::write_to_arduino(QByteArray d)
{
    if (serial->isWritable())
    {
        serial->write(d);
    }
    else
    {
        qDebug() <<"Erreur en ecriture";
    }
}

QByteArray arduino::read_from_arduino()
{
    if (serial->isReadable())
    {
        data=serial->readAll();
        return data;
    }
}
