#include "deserializacja.h"
#include <QDebug>


Deserializacja::Deserializacja()
{
    Logic = new Logika();


}


int Deserializacja::start(pakiet *pakietRevice)
{

    switch(pakietRevice->id)
    {case 0:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 1:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 2:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 3:
    {
      qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 4:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 5:
    {
    qDebug()<<"bla1"<<pakietRevice->id;
    }break;

    case 6:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 7:
    {
        AddUserPacket nowy;
        nowy.login="test!11";
        nowy.password="tajne haslo!";

        qDebug()<<"bla1"<<pakietRevice->id;
        baza.addUser(nowy);
    }break;
    case 8:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 9:
    {
      qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 10:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 11:
    {
    qDebug()<<"bla1"<<pakietRevice->id;
    }break;

    case 12:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 13:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 14:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 15:
    {
      qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 16:
    {
        qDebug()<<"bla1"<<pakietRevice->id;
    }break;
    case 17:
    {
    qDebug()<<"bla1"<<pakietRevice->id;
    }break;

    }


return 1;
}







