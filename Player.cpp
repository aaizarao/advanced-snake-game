#include "Player.h"

//CONSTRUCTOR
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(10,5,'*');
}

//DESTRUCTOR
Player::~Player()
{
    // delete any heap members here
}

//GETTER
void Player::getPlayerPos(objPos &returnPos) const
{
    // return the reference to the playerPos arrray list
    returnPos = playerPos;
}

//FSM
void Player::updatePlayerDir()
{
    // PPA3 input processing logic
}

//MOVEMENT
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added