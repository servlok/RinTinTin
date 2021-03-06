#include "tcpsocket.h"
#include <QThreadPool>
#include <iostream>
#include <QDebug>


TcpSocket::TcpSocket()
{

}


TcpSocket::TcpSocket(int port, int maxListeners) {
    this->sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);

    this->socketAdress.sin_family = AF_INET;
    this->socketAdress.sin_port = htons(port);
    this->socketAdress.sin_addr.s_addr = htonl(INADDR_ANY);
    this->maxSocketListeners = maxListeners;

    FD_ZERO(&(this->rfds));
    FD_SET(this->sock,&(this->rfds));

}


TcpSocket::TcpSocket(int& socket) {
   this->sock = socket;
}


TcpSocket::~TcpSocket(void) {
    close(this->sock);
}

int TcpSocket::bindSocket() {

    if ( bind(this->sock, (struct sockaddr*)&(this->socketAdress), sizeof(this->socketAdress)) == -1) {
       std::cout << "Wystapil blad podczas bindowania adresu!\n";
       return 1;
    }
    return 0;
}

int TcpSocket::setSockOpt() {
    int yep = 1;
    if( setsockopt(this->sock,SOL_SOCKET,SO_REUSEADDR, &yep ,sizeof(this->sock)) == -1) {
        std::cout<<"Wystapil blad podczas edycji opcji socketow!\n";
        return -1;
    }
    return 0;
}

int TcpSocket::listenSocket() {
    if( listen(this->sock, this->maxSocketListeners) == -1 ) {
        std::cout << "Ustawienie gniazda w tryb nasluchiwania nie powiodlo sie\n";
        return -1;
    }
    return 0;
}

int TcpSocket::acceptSocket() {
    int sock = accept(this->sock,0,0);
    if( sock == -1) {
        std::cout<<"Wystapil blad podczas akceptowania socketa!\n";
    }

    return sock;
}


void TcpSocket::sendPackage(std::string message) {
    unsigned int ileWyslano = 0;
    unsigned int nowaPartia = 0;
    const char* co = message.c_str();
    int rozmiar = message.size();
    fd_set writefds;
    while (ileWyslano < rozmiar) {


    FD_ZERO(&writefds);
    FD_SET(this->sock,&writefds);


    if(select(this->sock+1,NULL,&writefds,NULL,NULL)){
         nowaPartia = write(this->sock, co, rozmiar- ileWyslano);
          if (nowaPartia != -1) {
                    ileWyslano += nowaPartia;
                    co += nowaPartia;
                }
            }
        }
}

//int TcpSocket::sendPackage(std::string message) {
//    std::cout<<"wiadomosc do wyslania to: "<<message;
//    int operation;
//    for(int i = 0; i < message.size(); ++i) {
//        QChar ch = message[i];
//        operation = send(this->sock, &ch, 2,0);
//        if (operation == -1) {
//            std::cout<<"Wystapil blad podczas wysylania pakietu!\n";
//            return -1;
//        }
//    }

//    return message.size();
//}

bool TcpSocket::checkIfInvalid() {
    return this->sock == -1;
}

int TcpSocket::receivePackage(std::string& input) {
    input.clear();
    int operation;
    char mSize[3];
    std::string temp;
    int size;
    char data;
    bool goOut = false;
    for(int i = 0; !goOut; ++i) {
        operation = recv(this->sock, &mSize[i], 1, 0);
        if(operation == -1) {
            std::cout<<"Wystapil blad podczas odbierania pakietu!\n";
            return -1;
        }
        if(mSize[i] == '\n') {
            switch(i){
            case 0:
                return 0;
                break;
            case 1:
                temp += mSize[0];
                size = atoi(temp.c_str());
                break;
            case 2:
                temp += mSize[0];
                temp += mSize[1];
                size = atoi(temp.c_str());
                break;
            case 3:
                temp += mSize[0];
                temp += mSize[1];
                temp += mSize[2];
                size = atoi(temp.c_str());
                break;
            }

            goOut = true;
            break;
         }
         if(i == 3) {
             return 0;
        }
    }


    std::cout<<"Wielkosc pakietu przychodzacego "<<size;
    for(int i = 0; i < size; ++i) {
        operation = recv(this->sock, &data, 1, 0);
        if (operation == -1) {
            std::cout<<"Wystapil blad podczas odbierania pakietu!\n";
            return -1;
        }
        input += data;
    }

    return input.size();
}

void TcpSocket::closeSocket() {
    close(this->sock);
}

int TcpSocket::selectSocket() {
    return select((this->sock)+1,&(this->rfds),NULL,NULL,NULL);
}

int TcpSocket::selectTimedSocket() {
    return select((this->sock)+1,&(this->rfds),NULL,NULL,&time);
}

void TcpSocket::set(int newTime) {
    this->time.tv_sec = newTime;

    FD_ZERO(&(this->rfds));
    FD_SET(this->sock,&(this->rfds));
}
