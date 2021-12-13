// Created by Diane Duong
// Project 4 - Sort and Search
// Cannot find the last number because sorting function is against \n

#include <iostream>
#include <cstring>
#include <fstream>
#include <bits/stdc++.h> 
using namespace std;

//sort function extension
void swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
} 

//sort function
void bubbleSort(int *arr, int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
       
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
} 
//sort function
int binarySearch(int *arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 

//Keyboard function
int keyboardInput(int *list) {
    cout << "Please type ten integers: ";
    int i = 0;
    string num;
    do {
        cin >> num;
        if (cin.get() == '\n'){
            list[i] = stoi(num);
            break;
        }
        list[i] = stoi(num);
        i++;
        }
    while (true);
    return 0;
}

//file function
int fileInput(int *list) {
    fstream newfile;
    string fileName = "";
    while (fileName == ""){
        cout << "Enter File Name: ";
        cin >> fileName;
    }
    int i = 0;
    ifstream file(fileName);
    
    string str; 
    while (std::getline(file, str) && i < 100)
    {
        list[i] = stoi(str);
        i++;
    }
  return 0;
}


int main() 
{
    int list[150] = {};
    string m = "";
    while (m != "k" && m != "f"){
        cout << " Is the input from keyboard or file (type k or f): ";
        cin >> m;
        if (m == "k"){
            keyboardInput(list);
            int n = sizeof(list)/sizeof(list[0]); 
            bubbleSort(list, n);
        }
        else if(m == "f"){
            fileInput(list);
            int n = sizeof(list)/sizeof(list[0]); 
            bubbleSort(list, n);
        }
    }
    
    int numberSearch = 0;
    cout << "Please type a number for me to find: ";
    cin >> numberSearch;
    int indexx = -1;
    int n = sizeof(list) / sizeof(list[0]);
    while (numberSearch != -1){
        indexx = binarySearch(list, 0, n - 1, numberSearch); 
        if (indexx != -1){
            cout << "Found in index " << indexx << "\n";
        }else{
            cout << "Sorry\n";
        }
        cout << "Please type a number for me to find: ";
        cin >> numberSearch;
    }
    cout << "\n Bye";
  
    return 0;
}