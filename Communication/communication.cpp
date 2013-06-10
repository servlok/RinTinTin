#include "communication.h"
#include <iostream>
#include <QDebug>

Communication::Communication() :
    QRunnable()
{
}

Communication::Communication(TcpSocket* tcpsocket, SocketPool* socketPool) :
    QRunnable()
{
    this->tcpsocket = tcpsocket;
    this->pool = socketPool;

    this->setAutoDelete(true);
    this->parser = new ProtocolParser(tcpsocket);

}

void Communication::run() {
    std::string dataBuffer;
    int ret;
    int ret2;

    this->goOutC = false;

    while (!goOutC) {
            if((ret = this->tcpsocket->selectTimedSocket()) > 0 ) {
                ret2 = this->tcpsocket->receivePackage(dataBuffer);
                if(ret2 <= 0) {
                    if(ret2 == -1) {
                        goOutC = true;
                        break;
                    }
                } else {


                    std::cout<<"W buforze siedzi: "<<dataBuffer;
                    parser->parseIn(dataBuffer);
                    dataBuffer.clear();

                }

             } else {
                if(ret == -1) {

                    goOutC = true;
                    break;
                } else {//ret == 0

                    goOutC = true;
                    break;

                }
            }
    }

    std::cout<<"Rozlaczono\n";

}

void Communication::sendData(std::string message) {
    this->tcpsocket->sendPackage(message);
}

Communication::~Communication() {
    if(tcpsocket != NULL){
        this->tcpsocket->closeSocket();
        pool->clear(*tcpsocket);
        delete tcpsocket;
    }
    delete parser;
}
