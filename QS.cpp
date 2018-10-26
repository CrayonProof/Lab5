//#pragma once
#include <iostream>
#include <string>
#include "QS.h"
using namespace std;

QS::QS()
{
    array = 0;
    curInst = 0;
}
QS::~QS()
{
    delete [] array;
    curInst = 0;
}


void QS::sortAll()
{
    cout << "sortAll()" << endl;
    quickerSort(0, curInst - 1);
}

bool QS::quickSort(int first, int last)
{
    if((last-first)<1) return true;
    int pivot = medianOfThree(first, last);
    pivot = partition(first, last, pivot);
    quickSort(first, pivot-1);
    quickSort(pivot+1, last);
    
}

int QS::medianOfThree(int left, int right)
{
    cout << "medianOfThree(" << left << ", " << right << ")" << endl;
    
    int temp;
    
    if(curInst == 0 || left == right)
    {
        return -1;
    }
    int middle = (left + right) /2;
    
    bool sorted1 = false;
    bool sorted2 = false;
    while (!sorted1 || !sorted2)
    {
        if(array[left] > array[middle])
        {
            sorted1 = false;
            temp = array[left];
            array[left] = array[middle];
            array[middle] = temp;
        }
        else
        {
            sorted1 = true;
        }
        if(array[middle] > array[right])
        {
            sorted2 = false;
            temp = array[middle];
            array[middle] = array[right];
            array[right] = temp;
        }
        else
        {
            sorted2 = true;
        }
        
    }
    
    cout << "middle: " << middle << endl;
    
    return middle;
}

int QS::partition(int leftBound, int rightBound, int pivotInx)
{
    cout << "partition(" << leftBound << ", " << rightBound << ", " << pivotInx << ")" << endl;
    
    int temp;
    int up = leftBound;
    int down = rightBound;
    
    while (up < down)
    {
        while ((array[up]<=array[pivotInx]) && (up < rightBound)) { up++;}
        while ((array[down]>array[pivotInx]) && (down >leftBound)) { down--;}
        
        cout << "up: " << up << " down: " << down << endl;
        
        if (up < down)
        {
            temp = array[up];
            array[up] = array[down];
            array[down] = temp;
        }
        else
        {
            break;
        }
    }
    return up - 1;
}

/*
int temp;
    temp = array[left];
    array[left] = array[pivotIndex];
    array[pivotIndex] = temp;
    
    int up = left + 1;
    int down = right - 1;
    
    do
    {
        while ((array[up]<=array[left]) && (up < right)) { up++;}
        while ((array[down]>array[left]) && (down >left)) { down--;}
        
        if (up < down)
        {
            temp = array[up];
            array[up] = array[down];
            array[down] = temp;
        }
        
    } while (up < down);
    
    temp = array[left];
    array[left] = array[down];
    array[down] = temp;
    
    return down;
*/

string QS::getArray() const
{
    cout << "getArray()" << endl;
    string arraySt = "";
    if (curInst == 0 || array == 0)
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
    cout << "getSize()" << endl;
    return curInst;
}

bool QS::addToArray(int value)
{
    cout << "addToArray(" << value << ")" << endl;
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
    cout << "createArray(" << capacity << ")" << endl;
    curInst = 0;
    this->capacity = capacity;
    if(array != 0)
    {
        cout << "about to delete hope it goes ok" << endl;
        delete [] array;
        array = 0;
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
    cout << "clear()" << endl;
    curInst = 0;
    array = 0;
}

bool QS::quickerSort(int first, int last)
{
    cout << "quickerSort(" << first << ", " << last << ")" << endl;
    if((last-first) < 1) return true;
    int pivot = medianOfThree(first, last);
    pivot = partition(first, last, pivot);
    quickerSort(first, pivot-1);
    quickerSort(pivot+1, last);
    
}