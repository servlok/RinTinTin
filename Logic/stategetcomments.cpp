#include "stategetcomments.h"
#include <QDebug>
StateGetComments::StateGetComments()
{
}

void StateGetComments::start(std::vector<ResponseGetCommentsPacket> baza)
{
    this->baza=baza;
    qDebug()<<"starAAAAAAAAAAAAAAAt"<<baza.size();
}

ResponseGetCommentsPacket StateGetComments::rotate()
{

    ResponseGetCommentsPacket wynik = baza[0];
    baza.erase(baza.begin());

     qDebug()<<"rotate";

    return wynik;

}

bool StateGetComments::ifRotate()
{
    qDebug()<<"IFrotate"<<baza.size();
   if(baza.size())
        return true;
   else
        return false;
}
