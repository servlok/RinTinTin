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
    PacketType readPacketType(int& index, std::string data);

    ////////////////////////////////////////////////////////////IN//////////////////////////////////////////////////////////////////////
    PacketType readPacketType(int& index);

    AddUserPacket parseUserPacket(int index, std::string data);

    CheckRestaurantPacket parseCheckRestaurantPacket(int index, std::string data);

    GetRestaurantPacket parseGetRestaurantPacket(int index, std::string data);

    GetCommentsPacket parseGetCommentsPacket(int index, std::string data);

    AddCommentPacket parseAddCommentPacket(int index, std::string data );

    AddRestaurantPacket parseAddRestaurantPacket(int index, std::string data );

    DeleteCommentPacket parseDeleteCommentPacket(int index, std::string data );


    SendNextPacket parseSendNextPacket();
    /////////////////////////////////////////////////////////////////OUT/////////////////////////////////////////////////////////////////////

    std::string parsePacketOut(ResponseAddCommentPacket);
    std::string parsePacketOut(ResponseAddRestaurantPacket);
    std::string parsePacketOut(ResponseAddUserPacket);
    std::string parsePacketOut(ResponseCheckRestaurantPacket);
    std::string parsePacketOut(ResponseGetCommentsPacket);
    std::string parsePacketOut(ResponseGetRestaurantPacket);
    std::string parsePacketOut(PongPacket);
    std::string parsePacketOut(ResponseDeleteCommentPacket);
    std::string parsePacketOut(PingPacket packet);
    std::string parsePacketEndOfData();
    std::string parsePingPacket();

    ////////////////////////////////////////////////////////////////////////////////////////////////

    void deencryption(char* data);
    void encryption(std::string& data);
public:
    ProtocolParser(TcpSocket* sock);
    ~ProtocolParser();
    int parseIn(std::string data);

    int parseOut(Pakiet packet);

};

#endif // PROTOCOLPARSER_H

