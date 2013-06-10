#include "pakiet.h"

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
Pakiet::Pakiet()
{
    id = 20;
}



PingPacket::PingPacket()
{
    id = 0;
}

std::vector<std::string> PingPacket::stringi()
{
    std::vector<std::string> nowy;
    return nowy;
}

std::vector<int> PingPacket::inty()
{
    std::vector<int> nowy;
    return nowy;
}

PongPacket::PongPacket()
{
    id = 1;
}
std::vector<std::string> PongPacket::stringi()
{
    std::vector<std::string> nowy;
    return nowy;
}

std::vector<int> PongPacket::inty()
{
    std::vector<int> nowy;
    return nowy;
}

AddUserPacket::AddUserPacket()
{
    id = 2;
}
std::vector<std::string> AddUserPacket::stringi()
{
    std::vector<std::string> wynik;
    wynik.push_back(this->login);
    wynik.push_back(this->password);

    return wynik;
}

std::vector<int> AddUserPacket::inty()
{
    std::vector<int> wynik;
    wynik.push_back(this->id);

    return wynik;
}


 ResponseAddUserPacket:: ResponseAddUserPacket()
 {
     id = 3;
 }


 std::vector<std::string> ResponseAddUserPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> ResponseAddUserPacket::inty()
 {
     std::vector<int> wynik;
     wynik.push_back(this->userId);

     return wynik;
 }
 //////////////////////////////////////////////////////////////////////
 CheckRestaurantPacket::CheckRestaurantPacket()
 {
     id = 4;
 }

 std::vector<std::string> CheckRestaurantPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> CheckRestaurantPacket::inty()
 {
     std::vector<int> wynik;
     wynik.push_back(this->localLastRestaurantId);


     return wynik;
 }
 ///////////////////////////////////////////////////////////
 ResponseCheckRestaurantPacket::ResponseCheckRestaurantPacket()
 {
     id = 5;
 }

 std::vector<std::string> ResponseCheckRestaurantPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> ResponseCheckRestaurantPacket::inty()
 {
     std::vector<int> wynik;
     wynik.push_back(this->globalLastRestaurantId);
      wynik.push_back(this->globalRestaurantSize);


     return wynik;
 }
 //////////////////////////////////////////////////////////////
 GetRestaurantPacket::GetRestaurantPacket()
 {
     id = 6;
 }

 std::vector<std::string> GetRestaurantPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> GetRestaurantPacket::inty()
 {
     std::vector<int> wynik;
     wynik.push_back(this->toUpdateRestaurantId);



     return wynik;
 }
 ////////////////////////////////////////////////////////////////////////////////

 ResponseGetRestaurantPacket::ResponseGetRestaurantPacket()
 {
     id = 7;
 }

 std::vector<std::string> ResponseGetRestaurantPacket::stringi()
 {
     std::vector<std::string> nowy;
     nowy.push_back(this->restaurantAdress);
     nowy.push_back(this->restaurantName);
     nowy.push_back(this->restaurantType);
     return nowy;
 }

 std::vector<int> ResponseGetRestaurantPacket::inty()
 {
     std::vector<int> wynik;

      wynik.push_back(this->restaurantId);


     return wynik;
 }
 ///////////////////////////////////////////////////////////
 SendNextPacket::SendNextPacket()
 {
     id = 8;
 }

 std::vector<std::string> SendNextPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> SendNextPacket::inty()
 {
     std::vector<int> nowy;
     return nowy;
 }
 ////////////////////////////////////////////////////////////////

 EndOfDataPacket::EndOfDataPacket()
 {
     id = 9;
 }

 std::vector<std::string> EndOfDataPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> EndOfDataPacket::inty()
 {
     std::vector<int> nowy;
     return nowy;
 }
 ///////////////////////////

 GetCommentsPacket::GetCommentsPacket()
 {
     id = 10;
 }

 std::vector<std::string> GetCommentsPacket::stringi()
 {
     std::vector<std::string> nowy;
     nowy.push_back(this->addedDate);
     return nowy;
 }

 std::vector<int> GetCommentsPacket::inty()
 {
     std::vector<int> nowy;
     nowy.push_back(this->commentId);
     nowy.push_back(this->restaurantId);
     return nowy;
 }
///////////////////////////////////
 ResponseGetCommentsPacket::ResponseGetCommentsPacket()
 {
     id = 11;
 }

 std::vector<std::string> ResponseGetCommentsPacket::stringi()
 {
     std::vector<std::string> nowy;
     nowy.push_back(this->date);
     nowy.push_back(this->text);
     nowy.push_back(this->userLogin);
     return nowy;
 }

 std::vector<int> ResponseGetCommentsPacket::inty()
 {
     std::vector<int> nowy;

     return nowy;
 }

 ///////////////////////////

 AddCommentPacket::AddCommentPacket()
 {
     id = 12;
 }

 std::vector<std::string> AddCommentPacket::stringi()
 {
     std::vector<std::string> nowy;
     nowy.push_back(this->date);
     nowy.push_back(this->text);
     return nowy;
 }

 std::vector<int> AddCommentPacket::inty()
 {
     std::vector<int> nowy;
     nowy.push_back(this->restaurantId);
     nowy.push_back(this->userId);
     return nowy;
 }

 ////////////////////

 ResponseAddCommentPacket::ResponseAddCommentPacket()
 {
     id = 13;
 }

 std::vector<std::string> ResponseAddCommentPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> ResponseAddCommentPacket::inty()
 {
     std::vector<int> nowy;
     return nowy;
 }

 //////////////////////////

 AddRestaurantPacket::AddRestaurantPacket()
 {
     id = 14;
 }

 std::vector<std::string> AddRestaurantPacket::stringi()
 {
     std::vector<std::string> nowy;
     nowy.push_back(this->restaurantAdress);
     nowy.push_back(this->restaurantType);
     nowy.push_back(this->restaurantName);
     return nowy;
 }

 std::vector<int> AddRestaurantPacket::inty()
 {
     std::vector<int> nowy;
     return nowy;
 }


 ////////////////////////////

 ResponseAddRestaurantPacket::ResponseAddRestaurantPacket()
 {
     id = 15;
 }
 std::vector<std::string> ResponseAddRestaurantPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> ResponseAddRestaurantPacket::inty()
 {
     std::vector<int> nowy;
     return nowy;
 }

 /////////////////////

 DeleteCommentPacket::DeleteCommentPacket()
 {
     id = 16;
 }
 std::vector<std::string> DeleteCommentPacket::stringi()
 {
     std::vector<std::string> nowy;

     return nowy;
 }

 std::vector<int> DeleteCommentPacket::inty()
 {
     std::vector<int> nowy;
      nowy.push_back(this->commentId);
     return nowy;
 }

 //////////////////////////
 ResponseDeleteCommentPacket::ResponseDeleteCommentPacket()
 {
     id = 17;
 }


 std::vector<std::string> ResponseDeleteCommentPacket::stringi()
 {
     std::vector<std::string> nowy;
     return nowy;
 }

 std::vector<int> ResponseDeleteCommentPacket::inty()
 {
     std::vector<int> nowy;
     return nowy;
 }


