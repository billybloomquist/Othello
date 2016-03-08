#include "player.h"
#include <stdio.h>


// Small change

//Patrick's small Change

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish 
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    myBoard = new Board();
    mySide = side;
    
    if (mySide == BLACK)
        theirSide = WHITE;
    else
        theirSide = BLACK;
    

    /* 
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
	delete myBoard;
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be NULL.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return NULL.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /* 
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */ 
    int bestScore;
    int tempScore;
    Move *bestMove = NULL;
    if (opponentsMove != NULL)
    {
        myBoard->doMove(opponentsMove, theirSide);
    }
	
    if (myBoard->isDone() || myBoard->hasMoves(mySide) == false)
        return NULL;
	
    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Move *tempMove = new Move(i, j);
            if (myBoard->checkMove(tempMove, mySide))
            {
                Board *tempBoard = myBoard->copy();
                
                tempBoard->doMove(tempMove, mySide);
                tempScore = tempBoard->getScore(mySide);
                if (bestMove == NULL)
                {
                    bestScore = tempScore;
                    bestMove = new Move(tempMove->getX(), tempMove->getY());
                }
                else if (tempScore > bestScore)
                {
                    bestMove->setX(tempMove->getX());
                    bestMove->setY(tempMove->getY());
                    bestScore = tempScore;
                }
	            delete tempBoard;
            }
            delete tempMove;
        }
    }
    myBoard->doMove(bestMove, mySide);
    return bestMove;
}


