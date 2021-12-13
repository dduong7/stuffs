//Created by Diane Duong
// Project 3 - Simulating an elevator
//Solved bonus problem by applying a if-else loop. If zero is selected (1 in 7 chance) it continues, else re-rolls for 1 in 7 chance.

#include <iostream>
#include <stdlib.h>
#include <time.h> 

using namespace std;
int main()
{
    //Input of how many trips
    int trips = 0;
    cout << "How many trips do you want me to simulate: ";
    cin >> trips;

    //Floor Array
    int size = 7;
    int floors[7][7] = {};

    //customer asks to be taken to another random floor
    int y, x;
    srand(time(0));
    for(int i = 0; i < trips; i++)
    {   
        if(rand() % size == 0){
            y = 0;
        }
        else
        {
          y = rand() % size;  
        }
        
        if(rand() % size == 0){
            x = 0;
        }
        else
        {
          x = rand() % size;  
        }
        ++floors[y][x];
    }
    
    //Print table
    //Print top numbers for table
    cout << "   Going from    \t";
    for(y = 0; y < size; y++)
    {
        cout << y + 1 << "\t";
    }
    cout << "\n";
    
    //print table
    for(y = 0; y < size; y++) //Loops through y-axis
    {
        if(y == 0)
        {
            cout << "           To       " << y + 1 << "|\t"; //print left colum, the level on floor
        }
        else
        {
            cout << "                    " << y + 1 << "|\t"; //print left colum, the level on floor
        }
        
        for(x = 0; x < size; x++) //Loops through x-axis
        {
            cout << floors[y][x] << "\t"; 
        }
        cout << "\n"; //end of a-axis loop, creates new line
    }
    
   return 0;
}