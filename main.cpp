#include <QtCore/QCoreApplication>
#include <Communication/server.h>
#include <string>
#include <QTextCodec>
#include <QThreadPool>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int port = 10001;
int maxUsers = 1024;

int main(int argc, char *argv[])
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QCoreApplication a(argc, argv);
    QThreadPool::globalInstance()->setMaxThreadCount(maxUsers);

    if(argv[1] == NULL){
        Server(port,maxUsers).start();
    } else {
        if(argv[2] == NULL) {
            Server(atoi(argv[1]),maxUsers).start();
        } else {
            Server(atoi(argv[1]),atoi(argv[2])).start();
        }
    }



    return a.exec();
}
