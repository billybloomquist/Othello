#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include "common.h"
#include "board.h"
using namespace std;

class Player {
	
private:
	Board *myBoard;
	Side mySide;
	Side theirSide;

public:
    Player(Side side);
    ~Player();
    void setBoard(Board *newBoard);
    Move *doMove(Move *opponentsMove, int msLeft);
    

    // Flag to tell if the player is running within the test_minimax context
    bool testingMinimax;
};

#endif
