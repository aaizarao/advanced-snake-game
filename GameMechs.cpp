#include "GameMechs.h"
#include <time.h>

GameMechs::GameMechs() // used to initialize
{
    exitFlag = false;
    loseFlag = false;
    score = 0; 
    input = 0;
    srand((unsigned int) time(NULL));
}

GameMechs::GameMechs(int boardX, int boardY)
{
    // check if board size < 0
    if(boardX < 0 || boardY < 0){
        throw std::invalid_argument("Invalid values.");
    }

    boardSizeX = boardX;
    boardSizeY = boardY;
    exitFlag = false;
    loseFlag = false;
    score = 0; 
    input = 0;
    srand((unsigned int) time(NULL));
    
}

// do you need a destructor?

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
    if (MacUILib_hasChar()){
        input = MacUILib_getChar();
    }
    else{
        input = this_input;
    }
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here
void GameMechs::generateFood(objPosArrayList* playerPosList){
    int xRange = boardSizeX;
    int yRange = boardSizeY;
    int xmin = 1, xmax = xRange - 2;
    int ymin = 1, ymax = yRange - 2;

    char foodchar = 'o';
    int valid = 0;

    while (!valid){
        int playX = (rand() % (xmax - xmin + 1)) + xmin;
        int playY = (rand() % (ymax - ymin + 1)) + ymin;
        int clash = 0;

       int i;
       for (i = 0; i < playerPosList->getSize() ; i++){
            objPos snakeseg = playerPosList->getElement(i);
            if(playX == snakeseg.pos->x && playY == snakeseg.pos->y){ // check the positions for each segment
                clash = 1; // collision detected
                break; // continues looping and generating random numbersuntil valid equals 1
            }
       }

       if (clash == 0){
            food.setObjPos(playX, playY, foodchar); // store the food object
            valid = 1; // exit the loop
       }
  
    }

}

objPos GameMechs::getFoodPos() const{
    return food;
}