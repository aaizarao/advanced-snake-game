/////////////////////////////////////////////////////////////////
//COMP2SH4 FINAL PROJECT
//Authors: Aaiza Rao & Fatema Hasan
/////////////////////////////////////////////////////////////////

//REQUIRED LIBRARIES
#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h" //temorary


using namespace std;

//DEFINITIONS
#define DELAY_CONST 100000
#define length 20 //the boards x value
#define width 10 //the boards y value

//BOOLEANS
bool exitFlag;

//GLOBAL VARIABLES
char input;
Player* playerObj = nullptr;

//STRUCTS

//ENUMERATIONS

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

    while(exitFlag == false)  
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

    exitFlag = false; //not exiting
    input = 0; // NULL
   playerObj = new Player(nullptr); //temporary

}

//INPUT COLLECTION ROUTINE
void GetInput(void)
{
       if(MacUILib_hasChar()) //if a key on the keyboard is pressed
    {
        input = MacUILib_getChar(); //process the input by user
    }
}

//MAIN LOGIC ROUTINE
void RunLogic(void)
{
    
}

//DRAW SCREEN ROUTINE
void DrawScreen(void)
{
    MacUILib_clearScreen(); 

    //exiting the game (edit later)
    if(input == ' ')
    {
        exitFlag = true;
    }

    //temporary 
    objPos pPos;
    playerObj->getPlayerPos(pPos);

    //Game Board Setup
    int x,y;
    for(y=0; y<width;y++)
    {
        for(x=0;x<length;x++)
        {
            //top row  bottom row      left col  right col
            if(y==0 || y == width-1 || x == 0 || x == length-1)
            {
                MacUILib_printf("#");
            }
            //Drawing player '*' based on coordinate specified
            else if (x==pPos.pos-> x && y == pPos.pos-> y)
            {
                MacUILib_printf("%c", pPos.getSymbol());
            }
            //spaces throughout rest of the screen
            else
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

   delete playerObj;
}
