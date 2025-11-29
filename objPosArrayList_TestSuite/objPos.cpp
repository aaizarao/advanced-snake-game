#include "objPos.h"

objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

//COPY CONSTRUCTOR
objPos::objPos(const objPos& o)
{
    pos = new Pos; //allocating new heap memory
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

//COPY ASSIGNMENT OPERATOR
objPos& objPos::operator=(const objPos& o)
{
    if(this != &o) //checking if not copying self
    {
        delete pos; //delete current memory
        pos = new Pos; //add new memory to deep copy
        pos->x = o.pos->x;
        pos->y = o.pos->y;
        symbol = o.symbol;
    }

    return *this; //return current object
}

//MOVE CONSTRUCTOR
objPos::objPos(objPos&& o) noexcept
{
    //take other pointer
    pos = o.pos;
    symbol = o.symbol;
    //make other pointers empty
    o.pos = nullptr;
    o.symbol = 0;
}

//MOVE ASSIGNMENT OPERATOR
objPos& objPos::operator=(objPos&& o) noexcept
{
    if(this != &o)
    {
        delete pos; //delete old memory
        //take other pointer
        pos = o.pos;
        symbol = o.symbol;
        //make other pointers empty
        o.pos = nullptr;
        o.symbol = 0;
    }

    return *this; 
}

//DESTRUCTOR
objPos::~objPos()
{
    delete pos; //freeing heap memory
    pos=nullptr; //point the pos pointer to nothing
}

void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
