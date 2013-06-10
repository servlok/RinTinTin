#ifndef PROTOCOLPARSER_H
#define PROTOCOLPARSER_H

#include "packettype.h"
#include "../Deserialization/deserializacja.h"
#include "../Deserialization/pakiet.h"
#include "../Communication/tcpsocket.h"


class ProtocolParser
{
private:
    friend class Deserializacja;
    Deserializacja* deserialization;
    TcpSocket* tcpsocket;
    PacketType readPacketType(int& index, std::string data);

    ////////////////////////////////////////////////////////////IN//////////////////////////////////////////////////////////////////////
    PacketType readPacketType(int& index);

    AddUserPacket* parseUserPacket(int index, std::string data);

    CheckRestaurantPacket* parseCheckRestaurantPacket(int index, std::string data);

    GetRestaurantPacket* parseGetRestaurantPacket(int index, std::string data);

    GetCommentsPacket* parseGetCommentsPacket(int index, std::string data);

    AddCommentPacket* parseAddCommentPacket(int index, std::string data );

    AddRestaurantPacket* parseAddRestaurantPacket(int index, std::string data );

    DeleteCommentPacket* parseDeleteCommentPacket(int index, std::string data );


    SendNextPacket* parseSendNextPacket();
    /////////////////////////////////////////////////////////////////OUT/////////////////////////////////////////////////////////////////////

    void parsePacketOut(ResponseAddCommentPacket);
    void parsePacketOut(ResponseAddRestaurantPacket);
    void parsePacketOut(ResponseAddUserPacket);
    void parsePacketOut(ResponseCheckRestaurantPacket);
    void parsePacketOut(ResponseGetCommentsPacket);
    void parsePacketOut(ResponseGetRestaurantPacket);
    void parsePacketOut(PongPacket);
    void parsePacketOut(ResponseDeleteCommentPacket);
    void parsePacketOut(PingPacket packet);
    void parsePacketEndOfData();
    void parsePingPacket();

    ////////////////////////////////////////////////////////////////////////////////////////////////

    void deencryption(char* data);
    void encryption(std::string& data);
public:
    ProtocolParser(TcpSocket* sock);
    ~ProtocolParser();
    int parseIn(std::string data);

};

#endif // PROTOCOLPARSER_H

