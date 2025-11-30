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
    char input = mainGameMechsRef-> getInput();

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

    mainGameMechsRef-> clearInput();

}

//MOVEMENT
void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    int borderX = mainGameMechsRef-> getBoardSizeX();
    int borderY = mainGameMechsRef-> getBoardSizeY();
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
        x = borderX - 2; //wraparound to right side
    }

    else if(x >= borderX-1) //hits right side
    {
        x = 1; //wraparound to left side

    }

    if(y <= 0) //hits top side
    {
        y = borderY-2; //wraparound to bottom
    }

    else if(y >= borderY-1) //hits bottom side
    {
        y = 1; //wraparound to top
    }

    playerPos.setObjPos(x,y,playerPos.getSymbol());
}

// More methods to be added