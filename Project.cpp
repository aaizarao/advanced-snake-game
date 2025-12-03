/////////////////////////////////////////////////////////////////
//COMP2SH4 FINAL PROJECT
//Authors: Aaiza Rao & Fatema Hasan
/////////////////////////////////////////////////////////////////

//REQUIRED LIBRARIES
#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h" //temporary
#include "GameMechs.h"


using namespace std;

//DEFINITIONS
#define DELAY_CONST 100000

//GLOBAL VARIABLES

//POINTERS
GameMechs* gm = nullptr;
Player* playerObj = nullptr;

//FUNCTION PROTOTYPES
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


//MAIN PROGRAM
int main(void)
{

    Initialize();

    while(!gm-> getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}

//INITIALIZATION ROUTINE
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    gm = new GameMechs(20,10);
    playerObj = new Player(gm);

    //generating the intial food
    objPosArrayList snakeBody;
    playerObj->getPlayerPos(snakeBody);  // CORRECT - uses objPosArrayList
    gm->generateFood(&snakeBody);  // Pass pointer to the list
}

//INPUT COLLECTION ROUTINE
void GetInput(void)
{
    char cmd = 0;

    if(MacUILib_hasChar())
    {
        cmd = MacUILib_getChar();
    }
    gm->setInput(cmd);
}

//MAIN LOGIC ROUTINE
void RunLogic(void)
{
    char input = gm-> getInput();
    if(input == ' ')
    {
        gm-> setExitTrue();
    }

    playerObj-> updatePlayerDir();
    playerObj-> movePlayer();
    gm->clearInput();
}

//DRAW SCREEN ROUTINE
void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    //game win setup
    // if(gm-> getWinFlagStatus())
    // {
    //     MacUILib_printf("==== GAME OVER ====\n");
    //     MacUILib_printf("You collided with yourself!\n\n");
    //     MacUILib_printf("Final Score: %d\n", gm->getScore());
    //     MacUILib_printf("\nPress SPACE to exit ...\n");
    //     return;
    // }
    //game end setup
    if (gm-> getLoseFlagStatus())
    {
        MacUILib_printf("==== GAME OVER ====\n");
        MacUILib_printf("You collided with yourself!\n\n");
        MacUILib_printf("Final Score: %d\n", gm->getScore());
        MacUILib_printf("\nPress SPACE to exit ...\n");
        return;
    }

    //display controls
    MacUILib_printf("Score: %d\n", gm->getScore());
    MacUILib_printf("Controls: W A S D to move and SPACE to quit\n\n");

    objPosArrayList snake;
    playerObj->getPlayerPos(snake);

    objPos foodPos = gm->getFoodPos();


    //Game Board Setup
    int x,y;
    for(y=0; y<gm-> getBoardSizeY();y++)
    {
        for(x=0;x<gm-> getBoardSizeX();x++)
        {
            bool printed = false;
            //top row  bottom row      left col  right col
            if(y==0 || y == gm-> getBoardSizeY()-1 || x == 0 || x == gm-> getBoardSizeX()-1)
            {
                MacUILib_printf("#");
                printed= true;
            }
            //Drawing player '*' based on coordinate specified
            else if (x==foodPos.pos->x && y == foodPos.pos->y)
            {
                MacUILib_printf("%c", foodPos.getSymbol()); 
                printed = true;
            }

            else
            {
                int i;
                for (i = 0; i < snake.getSize(); i++)
                {
                    objPos Seg = snake.getElement(i);
                    if (Seg.pos->x == x && Seg.pos->y == y)
                    {
                        MacUILib_printf("%c",Seg.getSymbol());
                        printed = true;
                        break;
                    }
                }
            }
            
            if (!printed)
            {
                MacUILib_printf(" ");
            }     
                
        }

        MacUILib_printf("\n"); //print new line after going through loop every time

    }

}

//DELAY ROUTINE
void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

//TEAR-DOWN ROUTINE
void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

    delete gm;
    delete playerObj;
}