#pragma once
#include "pakiet.h"
#include "../Logic/logika.h"
#include "../Logic/dataaccessobject.h"
#include "../Parser/protocolparser.h"

class ProtocolParser;

class Deserializacja
{

public:
    void set(Logika * nowa);
    Logika * logic;
    Deserializacja(ProtocolParser *parser);
    ~Deserializacja();
    ProtocolParser* parser;
    int start(Pakiet *pakietRevice);
    void ResponseAddUser(ResponseAddUserPacket pakjet);

    void ResponseCheckRestaurant(ResponseCheckRestaurantPacket pakjet);

    void ResponseAddComment(ResponseAddCommentPacket pakjet);

    void ResponseAddRestaurant(ResponseAddRestaurantPacket pakjet);

    void ResponseDeleteComment(ResponseDeleteCommentPacket pakjet);

    void ResponseGetComments(ResponseGetCommentsPacket pakjet);

    void ResponseGetRestaurant(ResponseGetRestaurantPacket pakjet);

    void EndOfData();





};


