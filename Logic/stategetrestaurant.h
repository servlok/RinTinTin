#ifndef STATEGETRESTAURANT_H
#define STATEGETRESTAURANT_H
#include <vector>
#include "pakiet.h"
class StateGetRestaurant
{
    std::vector<ResponseGetRestaurantPacket> baza;
public:
    StateGetRestaurant();
    void start(std::vector<ResponseGetRestaurantPacket> baza);
    ResponseGetRestaurantPacket StateGetRestaurant::rotate();
    bool StateGetRestaurant::ifRotate();
};

#endif // STATEGETRESTAURANT_H
