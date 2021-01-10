#include <iostream>
#include "dll.hpp"
using namespace std;

DoubleLink::DoubleLink(){ //constructor

    head = NULL; //initialize head
    tail = NULL; //initialize tail
}

DoubleLink::~DoubleLink(){ //destructor

    Node *temp; //create temp node pointer

    while(head!=NULL){ //delete whole linked list
        temp = head->next; //move temp from head to end of list
        delete head; //delete at each iteration
        head = temp; //move the real head
    }
}

void DoubleLink::insertFirstDLL(int insertValue){ //NOT GOING TO USE THIS BECAUSE IT TAKES TOO LONG
   
   Node * newNode = new Node; //create a new node with allocated memory space

   if(head==NULL){ //if the head is empty, we insert the newNode as the first item in list
        head = newNode;
        newNode->prev = NULL;
        newNode->key = insertValue; //make the key of the new node our input
        newNode->next = NULL;
        head = newNode;
   }

   else{ //if the head is not empty...
        newNode->next = head; //
        newNode->prev = NULL;
        newNode->key = insertValue; //make the key of the new node our input
        head->prev = newNode;
        head = newNode;
   }
}

void DoubleLink::insertLastDLL(int insertValue){ //insert at the end of the dll
    
    Node *newNode = new Node; //allocate memory for a new node
    newNode->key = insertValue; //set new node's value to our insert value

    if(head==NULL){ //if the head is empty, we insert our newNode as the tail
        head = newNode; 
        newNode->prev = NULL;
        newNode->next = NULL;
        tail = newNode;
    }
    else{ //if head is not null, we insert at the end of the linked list
        newNode->prev = tail;
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
}

Node* DoubleLink::searchDLL(int insertValue){ //search the linked list for value we know will be in the list
    
    Node *current = head; //make a pointer to head node

    if(head==NULL){ //if the head of the linked list is empty, 
        return NULL;
    }

    while(current!=NULL){ //traverse through entire list
        if(current->key == insertValue){ //if current node data is the same as our input
            return current;//we found the node
            break; 
        }
        current = current->next; //otherwise, increment
    }

    return NULL; //if we did not find it, return nothing
}

void DoubleLink::displayDLL(){  //display from front to tail

    Node *current = head; //make a pointer to tail node

    while(current!=NULL){ //traverse from tail to head
        cout << current->key << " <--> ";
        current = current->next; //move to next node
    }

    if(current == NULL){ //if current ends up being NULL, we output and return
        cout << "NULL" << endl;
        return; //break
    }
}