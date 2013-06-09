#ifndef SERVER_H
#define SERVER_H

#include "tcpsocket.h"
#include "socketpool.h"

class Server
{
private:

    int port;
    int maxClients;
    TcpSocket* mainSocket;


public:
    Server(int port, int maxUsers);
    ~Server(void);
    int start();

};

#endif // SERVER_H
