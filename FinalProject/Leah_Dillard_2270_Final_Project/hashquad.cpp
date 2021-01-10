#include <iostream>
#include "hashquad.hpp"

using namespace std;

HashTable::HashTable(int bsize){// Constructor initializes table size and collision
    
    numOfCollision = 0;
    this->tableSize = bsize;
    table = new hashNode*[tableSize];
    for(int i = 0; i < bsize; i++){
        table[i] = NULL;
    }
} 

HashTable::~HashTable(){ //Destructor eliminates whole table
    
    for(int i = 0; i < tableSize; i++){
        if(table[i] != NULL){
            delete table[i];
            table[i] = NULL;
        }
    }
}

unsigned int HashTable::hashFunction(int key){

   return key%tableSize; //hash function per writeup
}

hashNode* HashTable::addNode(int key, hashNode*next){ //helper for insert function
    
    hashNode *newNode = new hashNode; //allocate new node 
    newNode->key = key; //set node data to our insert key
    newNode->next = next; //set node next
    return newNode; //return created node
}

void HashTable::insert(int key){ //insert a key into table

    if(!search(key)){//if the key doesnt already exist
        int index = hashFunction(key); //create an index to insert the key
        if(table[index]==NULL){ //if this index in the table is null...
            table[index] = addNode(key, table[index]); //then we add the node
        }

        else{ //if the index is occupied with another key
            numOfCollision++; //add one to collision counter every time we encounter a occupied bucket

            for(int i = 0; i < tableSize; i++){
                int newIndex = (index+i*i)%tableSize; //quadratic probe
                if(table[newIndex]==NULL){ //if this index is empty
                    table[newIndex] = addNode(key, table[newIndex]); //we add the node 
                    break; //break the loop
                }
            }
        } 
    }
}

int HashTable::getNumOfCollision(){

    return numOfCollision; //print calculated collisions from insert function
}

hashNode* HashTable::search(int key){ //use nodes to search for a given key

    int index = hashFunction(key); //find a hash index
    hashNode *currentNode = table[index]; //create node in the table at this index

    while(currentNode!=NULL){//if node is null
        if(currentNode->key==key){ //and node key matches input key
            return currentNode; //return node
        }
        currentNode = currentNode->next; //otherwise move on
    }
    return NULL; //if we did not find a key, return nothing
}

void HashTable::printTable(){ //print whole hash table

    for (int i = 0; i < tableSize; i++) {

        cout << i <<"|| ";
        hashNode *node = table[i]; //set new node pointer to table at index
        
        while(node!=NULL){ //traverse through table
        
            cout << node->key << " "; //print key
            node = node->next; //keep traversing
        }
    }
}


