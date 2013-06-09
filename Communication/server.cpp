#include "server.h"
#include "tcpsocket.h"
#include <iostream>
#include <signal.h>
#include <sys/socket.h>
#include <QThreadPool>
#include "communication.h"


SocketPool pool;
bool goOut;

Server::Server(int port, int maxUsers)
{
    this->port = port;
    this->maxClients = maxUsers;
}

Server::~Server(void)
{
    if(this->mainSocket != NULL){
        this->mainSocket->closeSocket();
        pool.clear(*mainSocket);
        delete mainSocket;
    }
}


void my_handler(int syg){
    std::cout<<"Przechwycono sygnal konca "<<syg<<std::endl;
    pool.clear();
    goOut = true;

}


int Server::start() {

    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);


    mainSocket = new TcpSocket(this->port,this->maxClients);
    if (mainSocket->setSockOpt() == -1) {
        delete mainSocket;
        return 1;
    }
    if (mainSocket->bindSocket() == -1) {
        delete mainSocket;
        return 1;
    }
    if (mainSocket->listenSocket() == -1) {
        delete mainSocket;
        return 1;
    }
    TcpSocket* clientSocket;
    Communication* clientHandler;
    std::cout<<"Start it!\n";
    goOut =false;
    while (!goOut) {
           if( mainSocket->selectSocket() >= 0 ) {
                int sock = mainSocket->acceptSocket();
                if (sock > 0) {
                    clientSocket = new TcpSocket(sock);
                    pool.add(*clientSocket);

                    clientSocket->set(180);

                    clientHandler = new Communication(clientSocket, &(pool));
                    QThreadPool::globalInstance()->start(clientHandler);
                    std::cout<<"Polaczenie\n";



                } else {
                    //acceptSocket() == -1
                    pool.clear();
                    goOut = true;
                    break;
                }
           } else {
               //selectSocket() == -1
               pool.clear();
               goOut = true;
               break;

           }
    }

   return 0;
}

