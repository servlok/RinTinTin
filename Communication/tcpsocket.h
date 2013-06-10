#ifndef TCPSOCKET_H
#define TCPSOCKET_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>
#include <string>

class TcpSocket
{
private:
    friend class SocketPool;
    int sock;
    struct sockaddr_in socketAdress;

    bool isTime;
    struct timeval time;
    fd_set rfds;

    int maxSocketListeners;


public:
    TcpSocket(int port, int maxListeners);
    TcpSocket();
    TcpSocket(int&);
    ~TcpSocket(void);

    int bindSocket();
    int listenSocket();
    bool checkIfInvalid();
    void closeSocket();
    int setSockOpt();
    int selectSocket();
    int selectTimedSocket();
    int acceptSocket();


    int receivePackage(std::string& input);

    int sendPackage(std::string message);
//    int sendPackage(std::string message);
    void set(int newTime);

    int operator==(const TcpSocket& tcp) {
        return this->sock == tcp.sock;
    }
};

#endif // TCPSOCKET_H
