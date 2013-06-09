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
    QString dataBuffer;
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


                    qDebug()<<"W buforze siedzi: "<<dataBuffer;
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

void Communication::sendData(QString message) {
    if( this->tcpsocket->sendPackage(message) == -1 ) {
        std::cout<<"Wystapil blad z wysylaniem pakietow!\n";
        this->goOutC = true;
    }
}

Communication::~Communication() {
    if(tcpsocket != NULL){
        this->tcpsocket->closeSocket();
        pool->clear(*tcpsocket);
        delete tcpsocket;
    }
}
