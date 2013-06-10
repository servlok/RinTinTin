
#pragma once

#include "dataaccessobject.h"
#include "statedefault.h"
#include "stategetcomments.h"
#include "stategetrestaurant.h"
#include "../Deserialization/pakiet.h"
//#include "deserializacja.h"

class Deserializacja;
class Logika
{




public:
    void set(Deserializacja * nowa);
    Logika(Deserializacja* deserializacja);
    ~Logika();
    int state;//0 DEFAULT // 1 GET RESTAURANTS //2 GET COMMENTS
    DataAccessObject * doa;
    StateDefault def;
    StateGetComments comments;
    StateGetRestaurant restaurant;
    Deserializacja * des;
    int * a;
    void setDB(DataAccessObject *db);


    void Service(Pakiet *pakietRevice);
};

