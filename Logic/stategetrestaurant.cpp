#include "stategetrestaurant.h"
#include <QDebug>
StateGetRestaurant::StateGetRestaurant()
{
}
void StateGetRestaurant::start(std::vector<ResponseGetRestaurantPacket> baza)
{
    this->baza=baza;
    qDebug()<<"start";
}

ResponseGetRestaurantPacket StateGetRestaurant::rotate()
{
 qDebug()<<"rotate";
    ResponseGetRestaurantPacket wynik = baza[0];
    baza.erase(baza.begin());
    qDebug()<<"rotate"<<baza.size();
    return wynik;


}

bool StateGetRestaurant::ifRotate()
{
     qDebug()<<"IFrotate"<<baza.size();
   if(baza.size())
        return true;
   else
        return false;
}
