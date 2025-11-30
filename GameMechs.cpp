#include "GameMechs.h"
#include <time.h>
#include "MacUILib.h" //temporary

GameMechs::GameMechs() // used to initialize
{
    boardSizeX = 20;
    boardSizeY = 10;
    exitFlag = false;
    loseFlag = false;
    score = 0; 
    input = 0;
    srand((unsigned int) time(NULL));
}

GameMechs::GameMechs(int boardX, int boardY)
{
    // check if board size < 0
    if(boardX <= 0 || boardY <= 0){
        boardX = 1;
        boardY = 1;
    }

    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0; 
    input = 0;
    srand((unsigned int) time(NULL));
    
}


bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score += 1;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;

}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    if(this_input !=0)
    {
        input = this_input;
    }
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

objPos GameMechs::getFoodPos() const
{
    return food;
}
void GameMechs::generateFood(objPosArrayList* playerPosList){

    int xmin = 1, xmax = boardSizeX - 2;
    int ymin = 1, ymax = boardSizeY - 2;

    char foodchar = 'o';

    while (true){
        int playX = (rand() % (xmax - xmin + 1)) + xmin;
        int playY = (rand() % (ymax - ymin + 1)) + ymin;
        bool clash = false;

       int i;
       for (i = 0; i < playerPosList->getSize() ; i++)
       {
            objPos snakeseg = playerPosList->getElement(i);
            if(snakeseg.pos->x == playX && snakeseg.pos->y ==playY){ // check the positions for each segment
                clash = true; // collision detected
            }
       }

       if (!clash){
            food.setObjPos(playX, playY, foodchar); // store the food object
            return;
       }
  
    }

}