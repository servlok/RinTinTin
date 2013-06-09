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

PongPacket::PongPacket()
{
    id = 1;
}

AddUserPacket::AddUserPacket()
{
    id = 2;
}
 ResponseAddUserPacket:: ResponseAddUserPacket()
 {
     id = 3;
 }
 CheckRestaurantPacket::CheckRestaurantPacket()
 {
     id = 4;
 }
 ResponseCheckRestaurantPacket::ResponseCheckRestaurantPacket()
 {
     id = 5;
 }
 GetRestaurantPacket::GetRestaurantPacket()
 {
     id = 6;
 }

 ResponseGetRestaurantPacket::ResponseGetRestaurantPacket()
 {
     id = 7;
 }

 SendNextPacket::SendNextPacket()
 {
     id = 8;
 }

 EndOfDataPacket::EndOfDataPacket()
 {
     id = 9;
 }

 GetCommentsPacket::GetCommentsPacket()
 {
     id = 10;
 }

 ResponseGetCommentsPacket::ResponseGetCommentsPacket()
 {
     id = 11;
 }

 AddCommentPacket::AddCommentPacket()
 {
     id = 12;
 }

 ResponseAddCommentPacket::ResponseAddCommentPacket()
 {
     id = 13;
 }

 AddRestaurantPacket::AddRestaurantPacket()
 {
     id = 14;
 }

 ResponseAddRestaurantPacket::ResponseAddRestaurantPacket()
 {
     id = 15;
 }

 DeleteCommentPacket::DeleteCommentPacket()
 {
     id = 16;
 }
 ResponseDeleteCommentPacket::ResponseDeleteCommentPacket()
 {
     id = 17;
 }


