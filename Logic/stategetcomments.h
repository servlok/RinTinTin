#ifndef STATEGETCOMMENTS_H
#define STATEGETCOMMENTS_H
#include "pakiet.h"
#include <vector>
class StateGetComments
{
    std::vector<ResponseGetCommentsPacket> baza;
public:
    StateGetComments();
    ResponseGetCommentsPacket StateGetComments::rotate();
    void StateGetComments::start(std::vector<ResponseGetCommentsPacket> baza);
    bool StateGetComments::ifRotate();
};

#endif // STATEGETCOMMENTS_H
