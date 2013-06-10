#pragma once
#include "logika.h"
#include <QDebug>
#include <iostream>
#include "../Deserialization/deserializacja.h"
Logika::Logika(Deserializacja* deserializacja)
{
    des= deserializacja;
    doa = new DataAccessObject();
    state = 0;
}

Logika::~Logika() {
    delete doa;
}

void Logika::set(Deserializacja  *nowa)
{
    this->des = nowa;
}

void Logika::setDB(DataAccessObject *db)
{
    this->doa=db;
}


void Logika::Service(Pakiet *pakietRevice)
{
    switch(pakietRevice->id)
    {case 0:
    {
        qDebug()<<"ping"<<pakietRevice->id;//NIC
    }break;
    case 1:
        {
            qDebug()<<"pong"<<pakietRevice->id;//NIC
        }break;
    case 2:
        {
        if(state==0)
            {


            AddUserPacket nowy;
            nowy.login=pakietRevice->stringi()[0];
            nowy.password=pakietRevice->stringi()[1];

            ResponseAddUserPacket lol = doa->addUser(nowy);


            this->des->ResponseAddUser(lol);

                }
        }break;
    case 3:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 4:
        {
        if(state==0){
           ResponseCheckRestaurantPacket wynik= doa->findNewestRestaurant();
        this->des->ResponseCheckRestaurant(wynik);

            }
        }break;
    case 5:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 6:
    {  qDebug()<<"wszedlem do 6";
        if(state ==0) {
             qDebug()<<"wszedlem do 6 state 1 ";
            state = 1;

            restaurant.start(doa->getRestaurant());

            if(!restaurant.ifRotate())
            {
                this->des->EndOfData();
                state =0;
                  qDebug()<<"if rotate tak";
            }
            else
            {
               ResponseGetRestaurantPacket nowy = restaurant.rotate();//WYSLANIE LISTY
               this->des->ResponseGetRestaurant(nowy);
               std::cout<<nowy.restaurantName;
            }

        }
        }break;
    case 7:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 8:
        {

        if(state == 1)
        {
            if(!restaurant.ifRotate())
            {
               this->des->EndOfData();
                state = 0;
                qDebug()<<"if rotate tak";
            }
            else
            {
                std::cout<<"if rotate nie";
                ResponseGetRestaurantPacket nowy = restaurant.rotate();//WYSLANIE LISTY
                this->des->ResponseGetRestaurant(nowy);
                std::cout<<nowy.restaurantName;
            }
        }
        else if(state == 2)
        {
            if(!comments.ifRotate())
            {
                //WYSLANIE END OF DATA
                state = 0;qDebug()<<"if rotate tak";
            }
            else
            {
                ResponseGetCommentsPacket nowy;
             nowy = comments.rotate();//WYSLANIE LISTY
             this->des->ResponseGetComments(nowy);
             std::cout<<"if rotate nie"<<nowy.text;
            }
        }
        }break;


    case 9:
        {
            //WYSRANIE END OF DATA//NIC
        }break;
    case 10:
        {
        if(state ==0){
        state = 2;
        GetCommentsPacket nowe;

        nowe.addedDate=pakietRevice->stringi()[0];
        nowe.restaurantId=pakietRevice->inty()[1];
        nowe.commentId=pakietRevice->inty()[0];
        qDebug()<<doa->getComment(nowe).size()<<"SRSLY?!?!?!?!?";
        comments.start(doa->getComment(nowe));

        if(!comments.ifRotate())
        {
            this->des->EndOfData();
            state =0;
            qDebug()<<"rotate TAK";
        }
        else
        {qDebug()<<"rotate NIE";
            ResponseGetCommentsPacket nowy;
            nowy =comments.rotate();
            this->des->ResponseGetComments(nowy);
            std::cout<<"KAKAKAKAK"<<nowy.text;
        }
        }
        }break;
    case 11:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 12:
        {
        if(state ==0)
        {
            AddCommentPacket nowy;
            nowy.date=pakietRevice->stringi()[0];
            nowy.text=pakietRevice->stringi()[1];

            nowy.restaurantId=pakietRevice->inty()[0];
            nowy.userId=pakietRevice->inty()[1];

            this->des->ResponseAddComment(doa->addComment(nowy));
        }
        }break;
    case 13:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 14:
        {
            if(state ==0)
            {
                AddRestaurantPacket nowy;
                nowy.restaurantAdress = pakietRevice->stringi()[0];
                nowy.restaurantType = pakietRevice->stringi()[1];
                nowy.restaurantName = pakietRevice->stringi()[2];

                this->des->ResponseAddRestaurant(doa->addRestaurant(nowy));
            }
        }break;
    case 15:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 16:
        {
            if(state ==0)
            {
                DeleteCommentPacket nowy;
                nowy.commentId=pakietRevice->inty()[0];

                this->des->ResponseDeleteComment(doa->deleteComment(nowy));
            }
        }break;
    case 17:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;

    }

}
