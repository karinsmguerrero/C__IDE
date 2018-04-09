//
// Created by karina on 29/03/18.
//

#ifndef C_IDE_LOCALSERVER_H
#define C_IDE_LOCALSERVER_H

#include "Server/loguru.hpp"
#include <QLocalServer>
#include <QLocalSocket>
#include <QTextStream>
#include <iostream>
#include <QMessageBox>
#include <JSON/JSONparser.h>

class QLocalSocket;
class LocalServer : public QLocalServer
{
Q_OBJECT
public:
    explicit LocalServer(QObject *parent = 0);
    void send(const QString &msg);
    void send(const QJsonDocument &msg);
    void read();
private:
    QLocalSocket *clientSocket;
    JSONparser *parser;

signals:

public slots:
};

#endif //C_IDE_LOCALSERVER_H
