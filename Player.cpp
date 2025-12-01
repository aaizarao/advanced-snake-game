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
    returnPos = *playerPosList;
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
    objPos currentFood = mainGameMechsRef->getFoodPos();

    if(newHead.pos->x == currentFood.pos->x && newHead.pos->y == currentFood.pos->y){
        playerPosList->insertHead(newHead); // get new head position
        mainGameMechsRef->generateFood(playerPosList); // generating a new food position
        mainGameMechsRef->incrementScore(); // increasing score after eating food
    }
    else {
        playerPosList->insertHead(newHead); // insert head in new position
        playerPosList->removeTail(); // remove the tail from old position in every iteration
    }
}

// More methods to be added