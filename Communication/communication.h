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
public:
    explicit Communication();
    Communication(TcpSocket* tcpsocket,SocketPool* socketPool);
    ~Communication();
    
    void run();
    void sendData(QString message);
};

#endif // COMMUNICATION_H
