#include <iostream>
#include "hashquad3.hpp"
using namespace std;

hashTable::hashTable(int inputSize){
    tableSize = inputSize;
}

int hashTable::hashFunction(int key){
    return key%tableSize;
}

void hashTable::quadraticHash(int t[], int arr[], int size){

    for(int i = 0; i < size; i++){
        int key = hashFunction(arr[i]);

        if(t[key]== 0){
            t[key]= arr[i];
        }
        else{
            for(int j = 0; j < tableSize; j++){
                int newKey = (key+j*j) % tableSize;
                if(t[newKey]==0){
                    t[newKey]=arr[i];
                    break;
                }
            }
        }
    }
}

void hashTable::printTable(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}