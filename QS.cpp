//#pragma once
#include <iostream>
#include <string>
#include "QS.h"
using namespace std;

QS::QS()
{
    curInst = 0;
}
QS::~QS() {}


void QS::sortAll()
{
    
}

int QS::medianOfThree(int left, int right)

{
    
}

int QS::partition(int left, int right, int pivotIndex)
{
    
}

string QS::getArray() const
{
    string arraySt = "";
    if (sizeof(array) == 0 || array == 0)
    {
        return "";
    }
    
    for(int i = 0; i < curInst; i++)
    {
        arraySt = arraySt + to_string(array[i]);
        if (i < curInst - 1)
        {
            arraySt = arraySt + ",";
        }
    }
    
    return arraySt;
}

int QS::getSize() const
{
    return curInst;
}

bool QS::addToArray(int value)
{
    if(curInst < capacity)
    {
        array[curInst] = value;
        curInst ++;
        return true;
    }
    else
    {
        return false;
    }
}

bool QS::createArray(int capacity)
{
    this->capacity = capacity;
    if(array != 0)
    {
        delete [] array;
        array = new int[capacity];
        return true;
    }
    else
    {
        array = new int[capacity];
        return true;
    }
    return false;
}

void QS::clear()
{
    curInst = 0;
    array = 0;
}