#pragma once
#include "types.h"
#include "square.h"
class Player{
    pType type;
    bool lost = false;
    public:
    Player(pType Ptype){
        type = Ptype;
    }
    pType getType(){
        return type;
    }
    bool getLost(){
        return lost;
    }
    void logic(pType player);
    void incPoints(Square *sq,pType type);
    void playPC(Square (&sq)[9]);
};
class OPP:public Player{
    int input;
    public:
    using Player::Player;
    void getInput(Square (&sq)[9]);
    void setInput(Square *sq);
};
