#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QRunnable>
#include <QObject>
#include "tcpsocket.h"
#include "socketpool.h"
#include "../Parser/protocolparser.h"

class Communication : public QRunnable
{
private:
    TcpSocket* tcpsocket;
    SocketPool* pool;
    ProtocolParser* parser;
    bool goOutC;
public:
    explicit Communication();
    Communication(TcpSocket* tcpsocket,SocketPool* socketPool);
    ~Communication();
    
    void run();
    void sendData(std::string message);
};

#endif // COMMUNICATION_H
