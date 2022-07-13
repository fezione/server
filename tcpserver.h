#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QDataStream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

class TcpServer : QTcpServer
{
    Q_OBJECT

public:
    TcpServer(QTcpServer *p = 0);
    ~TcpServer();

public slots:
    void accept_connection(); // Обрабатываем запрос на подключение
    void read_and_reply(); // читаем сообщение и отвечаем, затем отключаемся

private:
    QTcpServer *tServer;
    QTcpSocket *tSocket;
};

#endif // TCPSERVER_H
