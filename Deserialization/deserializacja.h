#ifndef DESERIALIZACJA_H
#define DESERIALIZACJA_H
#include "pakiet.h"
#include "../Logic/logika.h"
#include "dataaccessobject.h"

class Deserializacja
{
public:
    Logika * Logic;
    Deserializacja();
    //TODO Wskaznik na warstwe nizej
    int start(pakiet *pakietRevice);
    DataAccessObject baza;
};

#endif // DESERIALIZACJA_H
