#ifndef DATASENDER_H
#define DATASENDER_H
#include "tcpsocket.h"

class DataSender
{
private:
    TcpSocket* sock;
public:
    DataSender(TcpSocket *sock);
};

#endif // DATASENDER_H
