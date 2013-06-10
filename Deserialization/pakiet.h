#pragma once
#include <string>
#include <vector>
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
    virtual std::vector<std::string> stringi(){return std::vector<std::string>();}
    virtual std::vector<int> inty(){return std::vector<int>();}
};



class PingPacket : public Pakiet {
    public:
    PingPacket();
    int userId;
     std::vector<std::string> stringi();
     std::vector<int> inty() ;

};

class PongPacket : public Pakiet {
    public:
    PongPacket();
    int userId;
    std::vector<std::string> stringi();
    std::vector<int> inty() ;

};

class AddUserPacket : public Pakiet {
    public:
    AddUserPacket();
    std::string login;
    std::string password;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class ResponseAddUserPacket : public Pakiet {
    public:
    ResponseAddUserPacket();
    int userId;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class CheckRestaurantPacket : public Pakiet {
    public:
    CheckRestaurantPacket();
    int localLastRestaurantId;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class ResponseCheckRestaurantPacket : public Pakiet {
    public:
    ResponseCheckRestaurantPacket();
    int globalLastRestaurantId;
     int globalRestaurantSize;

     std::vector<std::string> stringi();
     std::vector<int> inty() ;
};

class GetRestaurantPacket : public Pakiet {
    public:
    GetRestaurantPacket();
    int toUpdateRestaurantId;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class ResponseGetRestaurantPacket : public Pakiet {
    public:
    ResponseGetRestaurantPacket();
    int restaurantId;
    std::string restaurantName;
    std::string restaurantAdress;
    std::string restaurantType;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class GetCommentsPacket : public Pakiet {
    public:
    GetCommentsPacket();
    int restaurantId;
    int commentId;
    std::string addedDate;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class ResponseGetCommentsPacket : public Pakiet {
    public:
    ResponseGetCommentsPacket();
    std::string userLogin;
    std::string text;
    std::string date;

    std::vector<std::string> stringi();
   std::vector<int> inty() ;
};

class AddCommentPacket : public Pakiet {
    public:
    AddCommentPacket();
    int userId;
    int restaurantId;
    std::string date;
    std::string text;

    std::vector<std::string> stringi();
   std::vector<int> inty() ;
};

class ResponseAddCommentPacket : public Pakiet {
    public:
    ResponseAddCommentPacket();
    int commentId;

   std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class AddRestaurantPacket : public Pakiet {
    public:
    AddRestaurantPacket();
    std::string restaurantName;
    std::string restaurantAdress;
    std::string restaurantType;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class ResponseAddRestaurantPacket : public Pakiet {
    public:
    ResponseAddRestaurantPacket();
    int restaurantId;


    std::vector<std::string> stringi();
   std::vector<int> inty() ;
};

class DeleteCommentPacket : public Pakiet {
    public:
    DeleteCommentPacket();
    int commentId;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class ResponseDeleteCommentPacket : public Pakiet {
    public:
    ResponseDeleteCommentPacket();
    bool ifDeleted;

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};

class SendNextPacket : public Pakiet{
public:
    SendNextPacket();

    std::vector<std::string> stringi();
   std::vector<int> inty() ;
};

class EndOfDataPacket : public Pakiet{

public :
    EndOfDataPacket();

    std::vector<std::string> stringi();
    std::vector<int> inty() ;
};



