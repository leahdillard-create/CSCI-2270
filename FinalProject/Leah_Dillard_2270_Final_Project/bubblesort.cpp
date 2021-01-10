#include <iostream>
#include <algorithm>
#include "bubblesort.hpp"
using namespace std;

void BubbleSorting::insertToTempArray(int arr[], int temparr[], int size){

    for(int i = 0; i<size; i++){ //copy values from array to temporary array
        temparr[i] = arr[i];
        //cout << "index "<< i << " copied: " << temparr[i] << endl;
    }
}

void BubbleSorting::bubbleSortHelper(int &x, int &y){ //pass by reference so values are reflected outside function
    
    int temp = x; //swap values using temp helper
    x = y;
    y = temp;
}

void BubbleSorting::printArray(int arr[], int length){ //print whole sorted array
  
    for(int i = 0; i < length; i++){ //traverse to length and print at index
        cout << arr[i] << " ";
    }

    cout << endl;
}

void BubbleSorting::bubbleSort(int arr[], int arrLength){ //main sorting algorithm
    
    for(int i = 0; i < arrLength; i++){ //traverse through entire array
        
        int swap = 0; //initialize a swap variable

        for(int j = 0; j < arrLength-i-1; j++){ 

            if(arr[j]>arr[j+1]){ //if the value of a number is > than the value of the upcoming number, we swap
                bubbleSortHelper(arr[j], arr[j+1]); //call helper
                swap = 1; 
            }
        }
        if(!swap){ //break the loop if we have nothing to swap
            break;
        }
    }
}

bool BubbleSorting::searchArray(int arr[], int length, int numToSearch){
    
    for(int i = 0; i < length; i++){ //traverse length of the array
        
        if(arr[i]==numToSearch){ //if the array at index finds the number we are searching for...
            return true; //return true and break for loop
        }

        else{
            continue; //otherwise, continue the loop
        }
    }
    
    return false; //if we can't find the number, return false
}