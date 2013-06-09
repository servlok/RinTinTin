#include "datasender.h"

DataSender::DataSender(TcpSocket* sock)
{
    this->sock = sock;
}


void DataSender::send(QString message) {
    sock->sendPackage(message);
}
