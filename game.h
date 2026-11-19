#pragma once
#include "square.h"
class Game{
    public:
    static Square squares[9];
    void display(Square sqs[]);
    void gameLoop(Square (&sqs)[9]);
};
