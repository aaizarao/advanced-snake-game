#include "Player.h"
#include "MacUILib.h" //temporary
 
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
    char input = 0;
    
    if(MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    switch(input)
    {
        //Move up
        case 'w':
        if(myDir != DOWN)
        {
            myDir = UP;
        }
        break;

        //Mode left
        case 'a':
        if(myDir != RIGHT)
        {
            myDir = LEFT;
        }
        break;

        //Move down
        case 's':
        if(myDir != UP)
        {
            myDir = DOWN;
        }
        break;

        //Move right
        case 'd':
        if(myDir != LEFT)
        {
            myDir = RIGHT;
        }
        break;

        default:
        break;
    }

}

//MOVEMENT
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    //temporary
    int len = 20;
    int wid = 10;
    int x = playerPos.pos->x;
    int y = playerPos.pos->y;

    switch(myDir)
    {
        case UP:
            y--;
            break;

        case LEFT:
            x--;
            break;

        case DOWN:
            y++;
            break;

        case RIGHT:
            x++;
            break;

        default:
            break;
    }

    //wraparound logic
    if(x <= 0) //hits left side
    {
        x = len - 2; //wraparound to right side
    }

    else if(x >= len-1) //hits right side
    {
        x = 1; //wraparound to left side

    }

    if(y <= 0) //hits top side
    {
        y = wid-2; //wraparound to bottom
    }

    else if(y >= wid-1) //hits bottom side
    {
        y = 1; //wraparound to top
    }

    playerPos.setObjPos(x,y,playerPos.getSymbol());
}

// More methods to be added