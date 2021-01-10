/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of CUBuilding structs to      */
/*     represet communication paths between buildings             */
/****************************************************************/

#include "CUBuildingNetwork.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CUBuildingNetwork::CUBuildingNetwork() {
    /* finished. do not touch. */
    head = NULL;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CUBuildingNetwork::isEmpty()
{
/* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: Add a new building to the network
 *   between the building *previous and the Building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfRoom)
{
    CUBuilding* current = new CUBuilding;
    current->name = buildingName;
    current->totalRoom = numOfRoom;

    while(current !=NULL && numOfRoom>current->totalRoom){
        previous = current;
        current = current->next;
    }
    if(previous == NULL){
        current->next = head;
        head = current;
        cout << "adding: " << buildingName << " (HEAD)" << endl;
    }
    else{
        current->next = previous->next;
        previous->next = current;
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
    }
    
}


/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    CUBuilding* current = new CUBuilding;
    head = current->next;

    addBuildingInfo(NULL, "FLMG", 2);
    
    addBuildingInfo(head, "DLC", 10);
    current = head->next;
    addBuildingInfo(current, "ECOT", 6);
    current = current->next;    
    addBuildingInfo(current, "CASE", 5);
    current = current->next;
    addBuildingInfo(current, "AERO", 4);
    current = current->next; 
    addBuildingInfo(current, "RGNT", 9);
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
   CUBuilding *current = head;
        while (current!=NULL){//same as current not equal to nullptr
            if(current->name == buildingName){
                return current; //is of type Node
            }
            current = current->next; //means you did not find it and keeps traversing
        }
    return 0;
}


/*
 * Purpose:
 * @param string receiver
 * @param string msg
 */
void CUBuildingNetwork::transmitRoomInfo(string receiver)
{
    if(isEmpty()){
        cout << "Empty List" << endl;

    }
    else if(searchForBuilding(receiver)==NULL){
        cout << "Building not found"<<endl;
    }
    else{
        string message;
        CUBuilding *node = new CUBuilding;
        node = head;

        while(node != NULL && node->name != receiver){
            node->numberMessages = node->numberMessages+1;
            cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message;
            cout << "available room at " << node->name << " is " << node->totalRoom << endl; 
            node = node -> next;
       }
        node->numberMessages=node->numberMessages+1;
        cout << node->name << " [# messages received: " << node->numberMessages << "] received: " << node->message;
        cout << "available room at " << node->name << " is " << node->totalRoom << endl; 
    }  
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    CUBuilding *current = head;
    cout << "== CURRENT PATH ==" << endl;

    if(isEmpty()){
        cout<<  "nothing in path" << endl;
    }
    else{
        while(current!=NULL){
            cout << current->name <<"(" <<current->totalRoom << ")" << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
}
