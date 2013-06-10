#ifndef STATEGETCOMMENTS_H
#define STATEGETCOMMENTS_H
#include "../Deserialization/pakiet.h"
#include <vector>
class StateGetComments
{
    std::vector<ResponseGetCommentsPacket> baza;
public:
    StateGetComments();
    ResponseGetCommentsPacket rotate();
    void start(std::vector<ResponseGetCommentsPacket> baza);
    bool ifRotate();
};

#endif // STATEGETCOMMENTS_H
