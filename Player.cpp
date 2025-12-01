#include "Player.h"
#include "MacUILib.h" //temporary
 
//CONSTRUCTOR
Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPosList = new objPosArrayList();
    objPos initialPos(10,5,'*');
    playerPosList->insertHead(initialPos); // inserting head in initial position
    // more actions to be included

}

//DESTRUCTOR
Player::~Player()
{
    delete playerPosList; // delete any heap members here
}

//GETTER
void Player::getPlayerPos(objPosArrayList &returnPos) const
{
    // return the reference to the playerPos arrray list
    while(returnPos.getSize() > 0)
    {
        returnPos.removeTail();
    }

    int i;
    for(i=0;i < playerPosList->getSize();i++)
    {
        returnPos.insertTail(playerPosList->getElement(i));
    }
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

    //first dont move until a direction is chosen
    if(myDir == STOP)
    {
        return;
    }
    int borderX = mainGameMechsRef-> getBoardSizeX();
    int borderY = mainGameMechsRef-> getBoardSizeY();

    objPos currentHead = playerPosList->getHeadElement();
    int x = currentHead.pos->x;
    int y = currentHead.pos->y;

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

    objPos newHead(x, y, '*'); // new object created for new head position
    
    //checking for self-collision
    int i;
    for(i =1; i<playerPosList->getSize();i++)
    {
        objPos seg = playerPosList->getElement(i);
        if(seg.pos->x == x && seg.pos->y == y)
        {
            mainGameMechsRef->setLoseFlag();
            mainGameMechsRef->setExitTrue();
            return;
        }
    }

    //checking for food collision
    objPos food = mainGameMechsRef->getFoodPos();

    if(x==food.pos->x && y == food.pos->y)
    {
        playerPosList->insertHead(newHead);
        mainGameMechsRef->incrementScore();
        mainGameMechsRef->generateFood(playerPosList);
    }
    else
    {
        playerPosList->insertHead(newHead);
        playerPosList->removeTail();
    }
}

// More methods to be added