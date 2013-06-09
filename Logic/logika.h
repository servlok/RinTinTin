#ifndef LOGIKA_H
#define LOGIKA_H
#include "dataaccessobject.h"
#include "statedefault.h"
#include "stategetcomments.h"
#include "stategetrestaurant.h"
#include "pakiet.h"
#include "deserializacja.h"
class Logika
{




public:
    int state;//0 DEFAULT // 1 GET RESTAURANTS //2 GET COMMENTS
    DataAccessObject doa;
    StateDefault def;
    StateGetComments comments;
    StateGetRestaurant restaurant;
    Deserializacja * des;




    Logika();
    void Service(pakiet *pakietRevice);
};

#endif // LOGIKA_H
