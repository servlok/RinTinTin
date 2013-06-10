#ifndef PAKIET_H
#define PAKIET_H
#include <string>
/*
 *	PING = 0,
    PONG = 1,
    ADD_USER = 2,
    RESPONSE_ADD_USER = 3,
    CHECK_RESTAURANT = 4,
    RESPONSE_RESTAURANT = 5,
    GET_RESTAURANT = 6,
    RESPONSE_GET_RESTAURANT = 7,
    SEND_NEXT = 8,
    END_OF_DATA = 9,
    GET_COMMENTS = 10,
    RESPONSE_GET_COMMENTS = 11,
    ADD_COMMENT = 12,
    RESPONSE_ADD_COMMENT = 13,
    ADD_RESTAURANT = 14,
    RESPONSE_ADD_RESTAURANT = 15,
    DELETE_COMMENT = 16,
    RESPONSE_DELETE_COMMENT = 17
 */
class Pakiet
{

public:
     int id;
    Pakiet();

       virtual ~Pakiet() {}
};



class PingPacket : public Pakiet {
    public:
    PingPacket();
    int userId;

};

class PongPacket : public Pakiet {
    public:
    PongPacket();
    int userId;

};

class AddUserPacket : public Pakiet {
    public:
    AddUserPacket();
    std::string login;
    std::string password;
};

class ResponseAddUserPacket : public Pakiet {
    public:
    ResponseAddUserPacket();
    int userId;
};

class CheckRestaurantPacket : public Pakiet {
    public:
    CheckRestaurantPacket();
    int localLastRestaurantId;
};

class ResponseCheckRestaurantPacket : public Pakiet {
    public:
    ResponseCheckRestaurantPacket();
    int globalLastRestaurantId;
     int globalRestaurantSize;
};

class GetRestaurantPacket : public Pakiet {
    public:
    GetRestaurantPacket();
    int toUpdateRestaurantId;
};

class ResponseGetRestaurantPacket : public Pakiet {
    public:
    ResponseGetRestaurantPacket();
    int restaurantId;
    std::string restaurantName;
    std::string restaurantAdress;
    std::string restaurantType;
};

class GetCommentsPacket : public Pakiet {
    public:
    GetCommentsPacket();
    int restaurantId;
    int commentId;
    std::string addedDate;
};

class ResponseGetCommentsPacket : public Pakiet {
    public:
    ResponseGetCommentsPacket();
    std::string userLogin;
    std::string text;
    std::string date;
};

class AddCommentPacket : public Pakiet {
    public:
    AddCommentPacket();
    int userId;
    int restaurantId;
    std::string date;
    std::string text;
};

class ResponseAddCommentPacket : public Pakiet {
    public:
    ResponseAddCommentPacket();
    int commentId;
};

class AddRestaurantPacket : public Pakiet {
    public:
    AddRestaurantPacket();
    std::string restaurantName;
    std::string restaurantAdress;
    std::string restaurantType;
};

class ResponseAddRestaurantPacket : public Pakiet {
    public:
    ResponseAddRestaurantPacket();
    int restaurantId;
};

class DeleteCommentPacket : public Pakiet {
    public:
    DeleteCommentPacket();
    int commentId;
};

class ResponseDeleteCommentPacket : public Pakiet {
    public:
    ResponseDeleteCommentPacket();
    bool ifDeleted;
};

class SendNextPacket : public Pakiet{
public:
    SendNextPacket();
};

class EndOfDataPacket : public Pakiet{

public :
    EndOfDataPacket();
};


#endif // PAKIET_H
