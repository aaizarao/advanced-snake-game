#include "objPos.h"

objPos::objPos()
{
    pos = nullptr;  // Initialize to null first
    pos = new Pos;  // Then allocate
    pos->x = 0;
    pos->y = 0;
    symbol = 0;
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
    if(this != &o)
    {
        // REUSE existing memory instead of delete/new
        pos->x = o.pos->x;    // Just copy the values
        pos->y = o.pos->y;
        symbol = o.symbol;
    }
    return *this;
}

//MOVE CONSTRUCTOR
objPos::objPos(objPos&& o) noexcept
{
    if(this != &o)
    {
        // Just copy values, don't delete/reallocate
        pos->x = o.pos->x;
        pos->y = o.pos->y;
        symbol = o.symbol;
        // Optionally reset the source if needed
        o.pos->x = 0;
        o.pos->y = 0;
        o.symbol = 0;
    }
}

//MOVE ASSIGNMENT OPERATOR
objPos& objPos::operator=(objPos&& o) noexcept
{
    if(this != &o)
    {
        if(pos != nullptr)    // ADD NULL CHECK
        {
            delete pos;
        }
        pos = new Pos;
        pos->x = o.pos->x;
        pos->y = o.pos->y;
        symbol = o.symbol;
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
    objPos returnPos(pos->x, pos->y, symbol);  // Use parameterized constructor
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
