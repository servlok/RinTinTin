#include "dataaccessobject.h"
#include <string>
#include <vector>
//#include "Logic/Server.h"
#include <QTextCodec>


DataAccessObject::DataAccessObject(void)
{

    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    QString login = "tin";
    QString password = "TYBv0kqRbnTF9XaE";

    db = new QSqlDatabase(  QSqlDatabase::addDatabase("QMYSQL"));

    db->setHostName("tin.jatokor.net");
    db->setDatabaseName("tin");
    db->setUserName(login);
    db->setPassword(password);


}


DataAccessObject::~DataAccessObject(void)
{
    delete db;
}

ResponseAddUserPacket DataAccessObject::addUser(AddUserPacket userToAdd) {
    ResponseAddUserPacket responsePacket;
    //TODO

    QSqlQuery query;
    db->open();

    query.prepare("INSERT INTO `tin`.`uzytkownik` (`nazwa`, `haslo`, `sesionID`, `admin`, `login_time`) VALUES (?, ?, ?,?, ?);");
    QString haslo = QString(userToAdd.password.c_str());
    QString nazwa = QString(userToAdd.login.c_str());

    query.bindValue(0, nazwa);
    query.bindValue(1, haslo);
    query.bindValue(2, 0);
    query.bindValue(3, 0);
    query.bindValue(4, "1000-01-01 00:00:00");


    query.exec();

    responsePacket.userId=query.lastInsertId().toInt();

     db->close();



    return responsePacket;
}

ResponseCheckRestaurantPacket DataAccessObject::findNewestRestaurant() {
    ResponseCheckRestaurantPacket responsePacket;

    GetRestaurantPacket packet;
    std::vector<ResponseGetRestaurantPacket> nowy = getRestaurant();
    responsePacket.globalLastRestaurantId = nowy[nowy.size()-1].restaurantId;
    responsePacket.globalRestaurantSize = nowy.size();


    return responsePacket;
}

std::vector<ResponseGetRestaurantPacket> DataAccessObject::getRestaurant() {
    //ResponseGetRestaurantPacket responsePacket;

    std::vector<ResponseGetRestaurantPacket> responsePacket;
    db->open();
    QSqlQuery query;

    query.prepare("SELECT * FROM restauracje");
    query.exec();


    for(int i=0;i<query.size();i++)
    {
        query.next();
       ResponseGetRestaurantPacket nowy;

       nowy.restaurantId = query.value(0).toInt();
       nowy.restaurantName = query.value(1).toString().toStdString();
       nowy.restaurantAdress = query.value(2).toString().toStdString();
       nowy.restaurantType = query.value(3).toString().toStdString();
       responsePacket.push_back(nowy);
    }



    db->close();




    return responsePacket;
}

std::vector<ResponseGetCommentsPacket> DataAccessObject::getComment(GetCommentsPacket packet) {
    ResponseGetCommentsPacket responsePacket;

    std::vector<ResponseGetCommentsPacket> wynik;
    db->open();
    QSqlQuery query;

    if(packet.addedDate=="0")
    {
        query.prepare("SELECT komentarz.tekst, komentarz.data, uzytkownik.nazwa FROM  `uzytkownik` INNER JOIN  `komentarz` ON komentarz.iduzytkownik_fk = uzytkownik.iduzytkownik where idRestauracje_fk = ? ORDER BY DATA DESC limit 0,5;");

        query.bindValue(0, packet.restaurantId);
        query.exec();


        for(int i=0;i<query.size();i++)
        {
              query.next();
              ResponseGetCommentsPacket nowy;
              nowy.text=query.value(0).toString().toStdString();
              nowy.date=query.value(1).toString().toStdString();
              nowy.userLogin=query.value(2).toString().toStdString();
              wynik.push_back(nowy);
        }
    }
    else
    {
        query.prepare("SELECT komentarz.tekst, komentarz.data, uzytkownik.nazwa FROM  `uzytkownik` INNER JOIN  `komentarz` ON komentarz.iduzytkownik_fk = uzytkownik.iduzytkownik where komentarz.data > ? and idRestauracje_fk = ? ORDER BY DATA DESC limit 0,5;");

        query.bindValue(0, QString(packet.addedDate.c_str()));
        query.bindValue(1, packet.restaurantId);


        query.exec();


        for(int i=0;i<query.size();i++)
        {
              query.next();
              ResponseGetCommentsPacket nowy;
              nowy.text=query.value(0).toString().toStdString();
              nowy.date=query.value(1).toString().toStdString();
              nowy.userLogin=query.value(2).toString().toStdString();
              wynik.push_back(nowy);
        }
    }



    db->close();


    return wynik;
}

ResponseAddCommentPacket DataAccessObject::addComment(AddCommentPacket packet) {
    ResponseAddCommentPacket responsePacket;

    QSqlQuery query;
    db->open();

    query.prepare("INSERT INTO `tin`.`komentarz` (`idRestauracje_fk`, `iduzytkownik_fk`, `tekst`, `data`) VALUES (?,?, ?,?);");


    int idRes= packet.restaurantId;
    int idUser= packet.userId;
    QString tekst = QString(packet.text.c_str());
    QString data = QString(packet.date.c_str());


    query.bindValue(0, idRes);
    query.bindValue(1, idUser);
    query.bindValue(2, tekst);
    query.bindValue(3, data);

    query.exec();

    responsePacket.commentId=query.lastInsertId().toInt();
    query.lastInsertId().toInt();

     db->close();

    return responsePacket;
}

ResponseAddRestaurantPacket DataAccessObject::addRestaurant(AddRestaurantPacket packet) {
    ResponseAddRestaurantPacket responsePacket;

    QSqlQuery query;
    db->open();

    query.prepare("INSERT INTO `tin`.`restauracje` (`nazwa`, `adres`, `typ`) VALUES (?, ?, ?);");
    QString nazwa = QString(packet.restaurantName.c_str());
    QString adres = QString(packet.restaurantAdress.c_str());
    QString typ = QString(packet.restaurantType.c_str());

    query.bindValue(0, nazwa);
    query.bindValue(1, adres);
    query.bindValue(2, typ);


    query.exec();
     responsePacket.restaurantId=query.lastInsertId().toInt();
     db->close();

    return responsePacket;
}

ResponseDeleteCommentPacket DataAccessObject::deleteComment(DeleteCommentPacket packet) {
    ResponseDeleteCommentPacket responsePacket;

    QSqlQuery query;
    db->open();

    query.prepare("DELETE FROM `tin`.`komentarz` WHERE `idkomentarz`= ?;");

    query.bindValue(0, packet.commentId);

    query.exec();



    db->close();
    return responsePacket;
}

