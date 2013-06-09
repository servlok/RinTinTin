#ifndef SOCKETPOOL_H
#define SOCKETPOOL_H

#include <list>
#include "tcpsocket.h"

class SocketPool
{
private:
    std::list<TcpSocket> socketPool;
public:
    SocketPool();
    ~SocketPool();
    void clear();
    void add(TcpSocket&);
    void clear(TcpSocket&);




};

#endif // SOCKETPOOL_H
