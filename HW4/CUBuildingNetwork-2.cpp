/****************************************************************/
/*                CUBuildingNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CUBuildingNetwork */
/*     This class uses a linked-list of Building structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CUBuildingNetwork-2.hpp"
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
 * Purpose: Add a new building to the network between the building *previous and the building that follows it in the network.
 * @param previous name of the Building that comes before the new Building
 * @param buildingName name of the new Building
 * @param numOfroom
 * @return none
 */
void CUBuildingNetwork::addBuildingInfo(CUBuilding* previous, string buildingName, int numOfroom) {
    // if we are passed an empty list, just create a new head node, and return

    if (head == NULL)
    {
        cout << "adding: " << buildingName << " (HEAD)" << endl;
        head = new CUBuilding;
        head->name = buildingName;
        head->numberMessages = 0;
        head->totalRoom = numOfroom;

        head->next = NULL;
    }
    // if it's not empty, we need to search for previous and append our node there.
    else if(previous == NULL )
    {
        cout << "adding: " <<buildingName<< " (HEAD)" << endl;
        CUBuilding *c = new CUBuilding;
        c->name = buildingName;
        c->numberMessages = 0;
        c->next = head;
        c->totalRoom = numOfroom;

        head = c;
    }else{
        cout << "adding: " << buildingName << " (prev: " << previous->name << ")" << endl;
        CUBuilding *newBuilding = new CUBuilding;
        newBuilding->name = buildingName;
        newBuilding->numberMessages = 0;
        newBuilding->next = previous->next;
        newBuilding->totalRoom = numOfroom;

        previous->next = newBuilding;
    }
}

/*
 * Purpose: populates the network with the predetermined buildings
 * @param none
 * @return none
 */
void CUBuildingNetwork::loadDefaultSetup()
{
    int num_buildings = 6;
    string buildings[] = {"FLMG", "DLC", "ECOT", "CASE", "AERO", "RGNT"};
    int rooms[] = {2,10,6,5,4,9};
    head = NULL;
    CUBuilding* prev = NULL;
    for(int i = 0; i < num_buildings; i++)
    {
        addBuildingInfo(prev, buildings[i],rooms[i]);
        prev = searchForBuilding(buildings[i]);
    }
}

/*
 * Purpose: Search the network for the specified building and return a pointer to that node
 * @param buildingName name of the building to look for in network
 * @return pointer to node of buildingName, or NULL if not found
 *
 */
CUBuilding* CUBuildingNetwork::searchForBuilding(string buildingName)
{
    // Search until the head is NULL, or we find the building
    CUBuilding* ptr = head;
    while (ptr != NULL && ptr->name != buildingName)
    {
        ptr = ptr->next;
    }
    // Return the node, or NULL
    return ptr;
}

/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CUBuildingNetwork::printNetwork() {
    cout << "== CURRENT PATH ==" << endl;
    // If the head is NULL
    CUBuilding* ptr = head;
    if (ptr == NULL)
        cout << "nothing in path" << endl;

    // Otherwise print each node, and then a NULL
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->name << "(" << ptr->totalRoom << ")" <<" -> ";
            ptr = ptr->next;
        }
        //cout << ptr->name << " -> ";
        cout << "NULL" << endl;
    }
    cout << "===" << endl;
  }

/*
 * Purpose: delete the building in the network with the specified name.
 * @param buildingName name of the building to delete in the network
 * @return none
 */
void CUBuildingNetwork::deleteCUBuilding(string buildingName) { 

    CUBuilding *temp = head;

    CUBuilding *to_be_deleted = searchForBuilding(buildingName);

    if(to_be_deleted!=NULL){ //if not at the end of the linked list
        if(head==to_be_deleted){ //deal with head
            head=head->next;
            delete to_be_deleted;
        }
        else if(to_be_deleted->next==NULL){ 
            while(temp->next != to_be_deleted){ //deal with tail
                temp = temp->next;
            }
            temp->next = NULL;
        }
        else{
            while(temp->next!=to_be_deleted){//deal with middle
                temp = temp->next;
            }
            temp->next=to_be_deleted->next;
            delete to_be_deleted;
        }
        
    }
    else{
            cout <<"Building does not exist." << endl;
    }
}
    /*        
    CUBuilding *temp = head;
    CUBuilding *previous = head;

    if(temp == NULL){
        return;
    }

    if(temp!=NULL &&temp->name==buildingName){
        head = temp->next;
        delete temp;
        return;
    }

    while(temp!=NULL&&temp->name != buildingName){
        previous = temp;
        temp = temp->next;
    }

    previous->next = temp->next;

    
    if(temp->name==buildingName){
        CUBuilding *to_be_deleted = temp->next;
        cout << buildingName << " deleted." << endl;
        temp->next=to_be_deleted->next;
        delete to_be_deleted;
        return;
    }
    */

/*
* Purpose: Creates a loop from last node to the building specified.
* @param buildingName name of the building to loop back
* returns the last node before loop creation (to break the loop)
*/
CUBuilding* CUBuildingNetwork::createLoop(string buildingName) {
    CUBuilding *temp = head;
    CUBuilding *intermediate =NULL;
    CUBuilding *tail;

    while(temp!=NULL){
        if(temp->name==buildingName){
            intermediate = temp; //store the node we were looking for in current
        }
        tail = temp;
        temp = temp->next;
    }

    if(intermediate!=NULL){ //if node was found...
        tail->next = intermediate;
    }
    return tail;
}

/*
 * Purpose: deletes all buildings in the network starting at the head building.
 * @param: none
 * @return: none
 */
void CUBuildingNetwork::deleteEntireNetwork()
{
    CUBuilding *temp = head;
    while(temp != NULL){
        CUBuilding *to_be_deleted = temp;
        temp = temp->next;
        cout << "deleting: " << to_be_deleted->name << endl;
        delete to_be_deleted;
    }
    
    cout << "Deleted network" << endl;
    head = NULL;
}

/*
 * Purpose: to detect loop in the linkedlist
 * @return: true if loop is detected.
 */
bool CUBuildingNetwork::detectLoop() {
    
    if(head==NULL){
        return false;
    }

    CUBuilding *second = head;
    CUBuilding *first = head->next;
    //move s one at a time and move f two nodes at a time
    //this will show us that they are both pointing to the same node
        
    while(first!=NULL && first->next!=NULL && second != NULL){
        if (first == second){ //if they reach the same spot
            return true;
        }
        first = first->next->next; //move forward 2
        second = second->next; //move forward once
    }
    return false;
}

/*
 * Purpose: Take the chunk of nodes from start index to end index
 *          Move that chunk at the end of the List
 * @param: start index, end index
 * @return: none
 */
void CUBuildingNetwork:: readjustNetwork(int start_index, int end_index)
{
    CUBuilding *temp = head;
    CUBuilding *counter = head;
    CUBuilding *prev = NULL;
    CUBuilding *start;
    CUBuilding *placeholder;
    CUBuilding *end;
    
    int count = 0;
    int length = 0;

    if(isEmpty()){ //if linked list is empty
        cout <<"Linked List is Empty" << endl;
        return;
    }

    while(counter!=NULL){
        length++;
        counter = counter->next;
    }

    if(start_index>end_index){
        cout <<"Invalid indices" << endl;
        return;
    }

    if(start_index<0||start_index>length){
        cout << "Invalid start index." << endl;
        return;
    }

    if(end_index<0||end_index>=length-1){
        cout << "Invalid end index" << endl;
        return;
    }

    while(temp!=NULL){
        if(count==end_index){
            end = temp;
        }
        if(count==start_index){
            start = prev;
            placeholder=temp;
        }

        prev = temp;
        temp=temp->next;
        count++;
    }

    prev->next = placeholder;

    struct CUBuilding *rearrange = end->next;
    end->next = NULL;

    if(start_index==0){
        head = rearrange;
    }
    else{
        start->next = rearrange;
    }
    

}