#pragma once

#include "../Deserialization/pakiet.h"
#include <QtSql>
#include <vector>
#include <QMutex>

class DataAccessObject
{
private:
    QSqlDatabase* db;
    QString login;
    QString password;
    QMutex mutex;
    DataAccessObject(void);

public:
    ResponseAddUserPacket addUser(AddUserPacket userToAdd);
    ResponseCheckRestaurantPacket findNewestRestaurant();
    std::vector<ResponseGetRestaurantPacket> getRestaurant();
    std::vector<ResponseGetCommentsPacket> getComment(GetCommentsPacket);
    ResponseAddCommentPacket addComment(AddCommentPacket);
    ResponseAddRestaurantPacket addRestaurant(AddRestaurantPacket);
    ResponseDeleteCommentPacket deleteComment(DeleteCommentPacket);


    static DataAccessObject& getInstance();
    ~DataAccessObject(void);
};


