#include "queArrCir.hpp"
#include <iostream>
#include "string"
using namespace std;

QueArrCir::QueArrCir(){
    head = 0;
    tail = 0;
    queSize = 0; //current size or count set to 0
}

bool QueArrCir::isEmpty(){
    if(queSize==0){
        return true;
    }
    else{
        return false;
    }
}

bool QueArrCir::isFull(){
    if(queSize==MAXSIZE){
        return true;
    }
    else{
        return false;
    }
}

void QueArrCir::enque(string newItem){
    if(!isFull()){
        a[tail] = newItem; //inserts word at 0
        queSize++;

        if(tail==MAXSIZE-1){ //handling condition of tail at the end
            tail = 0;
        }
        else{
            tail++; //move tail over an indeces
        }
    }
    else{
        cout << "queue is full" << endl;
    }
}

string QueArrCir::deque(){
    
    string output;

    if(!isEmpty()){
        output = a[head];
        queSize--;
        if(head==MAXSIZE-1){
            head = 0;
        }
        else{
            head++;
        }
        cout << "dequeing..." << endl;
    }
    else{
        cout << "queue empty. returning empty string" << endl;
        output = "";
    }
    return output;
}


