#pragma once
#include "deserializacja.h"
#include <QDebug>
#include <iostream>
#include "../Logic/logika.h"


Deserializacja::Deserializacja(ProtocolParser* parser)
{
   logic = new Logika(this);
   this->parser = parser;


}

Deserializacja::~Deserializacja(){
    delete logic;
}

void Deserializacja::set(Logika *nowa)
{
    this->logic=nowa;
}


int Deserializacja::start(Pakiet* pakietRevice)
{

    switch(pakietRevice->id)
    {case 0:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 1:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 2:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 3:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 4:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 5:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;

    case 6:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 7:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
       // baza.addUser(nowy);
    }break;
    case 8:
    {
         logic->Service(pakietRevice);
         std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 9:
    {
         std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 10:
    {
         logic->Service(pakietRevice);
         std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 11:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;

    case 12:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 13:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 14:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 15:
    {
      std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 16:
    {
        logic->Service(pakietRevice);
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;
    case 17:
    {
        std::cout<<"Przekazuje do sterowania pakiet: "<<pakietRevice->id<<std::endl;
    }break;

    }

    return 1;
}

void Deserializacja::ResponseAddUser(ResponseAddUserPacket pakjet)
{
    parser->parsePacketOut(pakjet);
    std::cout<<"Wywolano response dla "<<pakjet.userId<<std::endl;
}

void Deserializacja::ResponseCheckRestaurant(ResponseCheckRestaurantPacket pakjet)
{
    parser->parsePacketOut(pakjet);
    std::cout<<"Wywolano response dla"<<pakjet.globalLastRestaurantId<<" "<<pakjet.globalRestaurantSize<<std::endl;
}
////
void Deserializacja::ResponseAddComment(ResponseAddCommentPacket pakjet)
{
    parser->parsePacketOut(pakjet);
    std::cout<<"Wywolano response dla "<<pakjet.commentId<<std::endl;
}

void Deserializacja::ResponseAddRestaurant(ResponseAddRestaurantPacket pakjet)
{
    parser->parsePacketOut(pakjet);
    std::cout<<"Wywolano response dla "<<pakjet.restaurantId<<std::endl;
}
void Deserializacja::ResponseDeleteComment(ResponseDeleteCommentPacket pakjet)
{
    parser->parsePacketOut(pakjet);
    std::cout<<"Wywolano response dla "<<pakjet.ifDeleted<<std::endl;
}

void Deserializacja::ResponseGetComments(ResponseGetCommentsPacket pakjet)
{
    //wywolanie metody z wartwy nizej z argumentem pakjet
    std::cout<<"Wywolano response dla "<<pakjet.text<<std::endl;
}

void Deserializacja::ResponseGetRestaurant(ResponseGetRestaurantPacket pakjet)
{
    parser->parsePacketOut(pakjet);
    std::cout<<"Wywolano response dla "<<pakjet.restaurantName<<std::endl;
}

void Deserializacja::EndOfData()
{
    parser->parsePacketEndOfData();
    std::cout<<"Wywolano response dla "<<"END OF DATA\n";
}








