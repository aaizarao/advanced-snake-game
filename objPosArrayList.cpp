#include "objPosArrayList.h"
#include <stdexcept>

objPosArrayList::objPosArrayList(){ // default constructor
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList(){ // destructor
    delete[] aList; // deallocating data
}

objPos objPosArrayList::getHeadElement() const{
    if(listSize ==0)
    {
        throw std::out_of_range("List empty since no head element.");
    }
    return aList[0];
}

objPos objPosArrayList::getTailElement() const{
    if(listSize ==0)
    {
        throw std::out_of_range("List empty since no tail element.");
    }
    return aList[listSize - 1];
}

int objPosArrayList::getSize() const{
    return listSize;
}

objPos objPosArrayList::getElement(int index) const{
    if(index < 0 || index >= listSize)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return aList[index];
}

void objPosArrayList::insertHead(objPos thisPos){
    if(listSize >= arrayCapacity){
        throw std::overflow_error("No space left");
    }
    else{
        int i;
        for(i = listSize - 1; i >= 0; i--){
            aList[i+1] = aList[i]; // shifting of variables
        } 
        
        aList[0] = thisPos;
        listSize += 1;
    }

}

void objPosArrayList::insertTail(objPos thisPos){
    if(listSize>= arrayCapacity){
        throw std::overflow_error("No space left");
    }
    else{
        aList[listSize] = thisPos;
        listSize++;
    }

}

void objPosArrayList::removeHead(){
    if(listSize == 0){
        throw std::underflow_error("No elements left"); // empty list
    }
    else{
        int i;
        for(i = 1; i < listSize; i++){
            aList[i-1] = aList[i];
        }
        listSize--;
    }
}

void objPosArrayList::removeTail(){
    if(listSize == 0){ 
        throw std::underflow_error("No elements left"); // empty list
    }
    else{
        listSize--; // makes last element accessible
    }
}