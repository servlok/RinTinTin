#ifndef PROTOCOLPARSER_H
#define PROTOCOLPARSER_H

#include "packettype.h"
//#include "../Deserialization/deserializacja.h"
#include "../Deserialization/pakiet.h"
#include "../Communication/tcpsocket.h"


class ProtocolParser
{
private:
//    Deserializacja* deserialization;
    TcpSocket* tcpsocket;
    PacketType readPacketType(int& index, QString data);

    ////////////////////////////////////////////////////////////IN//////////////////////////////////////////////////////////////////////
    PacketType readPacketType(int& index);

    AddUserPacket parseUserPacket(int index, QString data);

    CheckRestaurantPacket parseCheckRestaurantPacket(int index, QString data);

    GetRestaurantPacket parseGetRestaurantPacket(int index, QString data);

    GetCommentsPacket parseGetCommentsPacket(int index, QString data);

    AddCommentPacket parseAddCommentPacket(int index, QString data );

    AddRestaurantPacket parseAddRestaurantPacket(int index, QString data );

    DeleteCommentPacket parseDeleteCommentPacket(int index, QString data );


    SendNextPacket parseSendNextPacket();
    /////////////////////////////////////////////////////////////////OUT/////////////////////////////////////////////////////////////////////

    QString parsePacketOut(ResponseAddCommentPacket);
    QString parsePacketOut(ResponseAddRestaurantPacket);
    QString parsePacketOut(ResponseAddUserPacket);
    QString parsePacketOut(ResponseCheckRestaurantPacket);
    QString parsePacketOut(ResponseGetCommentsPacket);
    QString parsePacketOut(ResponseGetRestaurantPacket);
    QString parsePacketOut(PongPacket);
    QString parsePacketOut(ResponseDeleteCommentPacket);
    QString parsePacketOut(PingPacket packet);
    QString parsePacketEndOfData();
    QString parsePingPacket();

    ////////////////////////////////////////////////////////////////////////////////////////////////

    void deencryption(char* data);
    void encryption(QString& data);
public:
    ProtocolParser(TcpSocket* sock);
    ~ProtocolParser();
    int parseIn(QString data);

    int parseOut(Pakiet packet);

};

#endif // PROTOCOLPARSER_H

