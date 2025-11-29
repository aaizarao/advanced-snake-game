#include <iostream>
#include "objPosArrayList.h"
#include "objPos.h"

using namespace std;

objPosArrayList::objPosArrayList(){ // default constructor
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;

    arrayCapacity = ARRAY_MAX_CAP;
}

objPosArrayList::~objPosArrayList(){ // destructor
    delete[] aList; // deallocating data
}

objPos objPosArrayList::getHeadElement() const {
    return aList[0];
}

objPos objPosArrayList::getTailElement() const {
    return aList[listSize - 1];
}

int objPosArrayList::getSize() const {
    return listSize;
}

objPos objPosArrayList::getElement(int index) const {
    return aList[index];
}

void objPosArrayList::insertHead(objPos thisPos){
    if(listSize == arrayCapacity){
        cout << "No space left" << endl;
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
    if(listSize == arrayCapacity){
        cout << "No space left" << endl;
    }
    else{
        aList[listSize] = thisPos;
        listSize++;
    }

}

void objPosArrayList::removeHead(){
    if(listSize == 0){
        cout << "No elements left" << endl; // empty list
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
        cout << "No elements left" << endl; // empty list
    }
    else{
        listSize--; // makes last element accessible
    }
}