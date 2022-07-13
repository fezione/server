#include <QCoreApplication>
#include <iostream>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "--- TCP Server ---" << std::endl;
    TcpServer ts;

    return a.exec();
}
