#include "logika.h"
#include "QDebug"
Logika::Logika()
{
   // this->des=des;
    state = 0;
}


void Logika::Service(pakiet *pakietRevice)
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
            {//doa.addUser(pakietRevice);
            AddUserPacket dostalem;
            ResponseAddUserPacket lol = doa.addUser(dostalem);
          //  des->responseAddUser(lol);
            //wywolanie metody response add user

                }
        }break;
    case 3:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 4:
        {
        if(state=0){
           ResponseCheckRestaurantPacket wynik= doa.findNewestRestaurant();
         //  des->responseFindNewestRestaurant(wynik);
            }
        }break;
    case 5:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;
    case 6:
    {  qDebug()<<"wszedlem do 6";
        if(state ==0){
             qDebug()<<"wszedlem do 6 state 1 ";
            state = 1;

            restaurant.start(doa.getRestaurant());

            if(!restaurant.ifRotate())
            {
                //wyslanie end of data
                state =0;
                  qDebug()<<"if rotate tak";
            }
            else
            {
               ResponseGetRestaurantPacket nowy = restaurant.rotate();//wyslanie restauracji
               qDebug()<<nowy.restaurantName;
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
                //wyslanie end of data
                state = 0;
                qDebug()<<"if rotate tak";
            }
            else
            {
                qDebug()<<"if rotate nie";
                ResponseGetRestaurantPacket nowy = restaurant.rotate();//wyslanie restauracji
                qDebug()<<nowy.restaurantName;
            }
        }
        else if(state == 2)
        {
            if(!comments.ifRotate())
            {
                //wyslanie end of data
                state = 0;qDebug()<<"if rotate tak";
            }
            else
            {
                ResponseGetCommentsPacket nowy;
             nowy = comments.rotate();//wyslanie restauracji
             qDebug()<<"if rotate nie"<<nowy.text;
            }
        }
        }break;


    case 9:
        {
            //WYSRANIE END OF DATA//NIC
        }break;
    case 10:
        {
        state = 2;
        GetCommentsPacket nowe;///przejsciowe
        nowe.addedDate="0";
        nowe.restaurantId=1;
        comments.start(doa.getComment(nowe));

        if(!comments.ifRotate())
        {
            //wyslanie end of data
            state =0;
            qDebug()<<"rotate TAK";
        }
        else
        {qDebug()<<"rotate NIE";
            ResponseGetCommentsPacket nowy;
            nowy =comments.rotate();//wyslanie restauracji
            qDebug()<<"KAKAKAKAK"<<nowy.text;
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
            AddCommentPacket nowy;//tymaczsowe
            doa.addComment(nowy);
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
                AddRestaurantPacket nowy;//tymaczsowe
                doa.addRestaurant(nowy);
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
                DeleteCommentPacket nowy;//tymaczsowe
                doa.deleteComment(nowy);
            }
        }break;
    case 17:
        {
            qDebug()<<"bla1"<<pakietRevice->id;//NIC
        }break;

    }

}
