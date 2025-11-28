#include "GameMechs.h"

GameMechs::GameMechs() // used to initialize
{
    exitFlag = false;
    loseFlag = false;
    score = 0; 
    input = 0;
}

GameMechs::GameMechs(int boardX, int boardY)
{
    // check if board size < 0
    if(boardX < 0 || boardY < 0){
        throw std::invalid_argument("Invalid values.");
    }

    boardSizeX = boardX;
    boardSizeY = boardY;
    
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
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here