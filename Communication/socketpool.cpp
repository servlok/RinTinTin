#include "socketpool.h"

SocketPool::SocketPool()
{
}

SocketPool::~SocketPool()
{
    this->clear();
    this->socketPool.clear();
}


void SocketPool::clear() {
    for(std::list<TcpSocket>::iterator it = this->socketPool.begin(); it != this->socketPool.end();) {
            close((*it).sock);
    }
}

void SocketPool::add(TcpSocket& toAdd) {
    this->socketPool.push_back(toAdd);
}

void SocketPool::clear(TcpSocket& toDel) {
    for(std::list<TcpSocket>::iterator it = this->socketPool.begin(); it != this->socketPool.end(); ++it) {
        if( (*it) ==  toDel) {
            close((*it).sock);
        }
    }
}
