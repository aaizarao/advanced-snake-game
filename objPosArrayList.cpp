#include "objPosArrayList.h"

objPosArrayList::objPosArrayList(){ // default constructor
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

    // Initialize ALL elements to avoid destructor issues
    for(int i = 0; i < ARRAY_MAX_CAP; i++)
    {
        aList[i].pos = new Pos;  // Ensure every element has valid memory
        aList[i].pos->x = 0;
        aList[i].pos->y = 0;
        aList[i].symbol = 0;
    }
}

objPosArrayList::~objPosArrayList(){ // destructor
    delete[] aList; // deallocating data
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
     if(listSize <= 0) {
        return objPos(0, 0, ' ');  // Return default instead of crashing
    }
    return aList[listSize - 1];
}

int objPosArrayList::getSize() const{
    return listSize;
}

objPos objPosArrayList::getElement(int index) const
{
    if(index < 0 || index >= listSize) {
        return objPos(0, 0, ' ');  // Return default instead of crashing
    }
    return aList[index];
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize >= arrayCapacity)
    {
        return;
    }
    int i;
    for(i = listSize - 1; i >= 0; i--)
    {
        aList[i+1] = aList[i]; // shifting of variables
    } 
        
    aList[0] = thisPos;
    listSize ++;
    

}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize>= arrayCapacity)
    {
        return;
    }

    aList[listSize] = thisPos;
    listSize++;

}

void objPosArrayList::removeHead()
{
    if(listSize == 0)
    {
        return;
    }
    int i;
    for(i = 1; i < listSize; i++)
    {
        aList[i-1] = aList[i];
    }

    aList[listSize - 1].setObjPos(0, 0, 0);
    listSize--;
}


void objPosArrayList::removeTail(){
    if(listSize == 0)
    { 
        return;
    }

    aList[listSize - 1].setObjPos(0, 0, 0);  // Reset to default
    listSize--; // makes last element accessible
    
}