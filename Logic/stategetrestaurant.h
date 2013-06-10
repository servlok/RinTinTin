#ifndef STATEGETRESTAURANT_H
#define STATEGETRESTAURANT_H
#include <vector>
#include "../Deserialization/pakiet.h"
class StateGetRestaurant
{
    std::vector<ResponseGetRestaurantPacket> baza;
public:
    StateGetRestaurant();
    void start(std::vector<ResponseGetRestaurantPacket> baza);
    ResponseGetRestaurantPacket rotate();
    bool ifRotate();
};

#endif // STATEGETRESTAURANT_H
