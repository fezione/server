#include "tcpserver.h"

#include <QByteArray>
#include <QHostAddress>
#include <iostream>
#include "tcpserver.h"

const quint16 PORT = 2333;

TcpServer::TcpServer(QTcpServer *p) :
    QTcpServer(p)
{
    tServer = new QTcpServer;
    tSocket = new QTcpSocket;

    /* Порт прослушивания */
    if(tServer->listen(QHostAddress::Any, PORT))
        std::cout << "--- Linsting to Port ---" << std::endl;
    else
        std::cout << "*** FAIL LISTING ***" << std::endl;

    /* Обработка нового запроса на подключение */
    connect(tServer, SIGNAL(newConnection()),
        this, SLOT(accept_connection()));
}

TcpServer::~TcpServer()
{
    delete tServer;
    delete tSocket;
}

void TcpServer::accept_connection()
{
    std::cout << "--- Accept Connection ---" << std::endl;

    /* Сервер подключает свой сокет к клиентскому сокету */
    tSocket = tServer->nextPendingConnection();

    /* Socket читает и отвечает, как только получает информацию */
    connect(tSocket, SIGNAL(readyRead()),
        this, SLOT(read_and_reply()));
}

void TcpServer::read_and_reply()
{
    std::cout << "--- Read Message ---" << std::endl;

    /* Прочитать информацию */
        QByteArray ba1 = tSocket->readAll();
        std::cout << ba1.data() << std::endl;
        std::cout << "--- Reply ---" << std::endl;

    /* Ответить */
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly );
        out.setVersion( QDataStream::Qt_DefaultCompiledVersion);

        out << quint16(0)
            << quint8(0x10) << quint16(3)
            << quint8(255) << quint8(15) << quint8(100);

        out.device()->seek(0);
        out << quint16( block.size() - sizeof(quint16) );

        tSocket->write( block );

    Sleep( 1000 );

    /* Ответить */
        QByteArray block1;
        QDataStream out1(&block1, QIODevice::WriteOnly );
        out1.setVersion( QDataStream::Qt_DefaultCompiledVersion);

        out1 << quint16(0)
            << quint8(0x13) << quint16(0);

        out1.device()->seek(0);
        out1 << quint16( block1.size() - sizeof(quint16) );

        tSocket->write( block1 );

    tSocket->close();
}
