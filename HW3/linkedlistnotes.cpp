
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

/*
ABSTRACT DATA TYPE
- is like an interface/contract
- defines operations that will support it
- doesn't define the algorithms
- no implementation details

DATA STRUCTURE
- specific/ concrete implementation of an ADT
- singly, doubly, circular, etc.

* A linked list is an abstract data type!!

SINGLY LINKED LIST:
- in a singly linked list, each element, which is also called
a node, contains the data stored in the node and a pointer to the
next node in the list

- a node is essentially an integer key

- first node is a head node that points to first item in list
- a single node contains two values: key and next
- next is a pointer to the next node in the list
- last element of list points to null

- each individual node has a separate memory address
- unlike an array, linked list nodes are not contiguous in memory
- they're scattered all over

DOUBLY LINKED LIST:
- each node has three properties: an integer key,
a pointer to the next node in the list, and a pointer 
to the previous node in the list


LINKED LIST AS ABSTRACT DATA TYPE
-Basic operations on the linked list
    -initialize the list
    -determine whether the list is empty
    -print the list
    -find length of list
    -destroy list
    -retrieve infor contained in the first node
    -retrieve the info contained in the last node
    -search the list for a given item
    -insert an item in the list
    -delete an item from the list
    -make a copy of the linked list

-main OPERATIONS
    -prepent(value) : add a node in the beginning
    -append(value) : add a node in the end
    -pop() : remove a node from the end
    -popFirst() : remove a node from the beginning
    -head() : return the first node
    -tail() : return the last node
    -deleteNode(node) : remove node from the list


//currentNode = LinkedList.head() assigned to head value
//head and the current node you created are both pointing to 1
//don't want to mess with head node,



struct Node{
    int data; //data field
    Node *next; //next pointer
};

Node *head; //variable declaration
//head must be of type node because it points to first list element
//says where the beginninng of the list is so we can run different operations
//assists and is a marker
// head -> data is equivalent to (*head).data
// (*(head.next).data) is equivalent to head-> next -> data
// use dot to access members of a struct, but arrow to access pointers

Node *current;

current = head; //copies value of head into current

current = current -> next; // copies over value of current->next to current, which is 2800




class LinkedList{
    private: 
        Node *head;

    public:
        LinkedList(); //constructor
        LinkedList(); //deconstructor
        void traverse();
        Node *search(int val);
        void insertNode(int leftValue, int value);
        void deleteNode(int value);
};

int main(){

    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;

    Node *head = NULL;


    //allocate 3 nodes in the heap & have head, second, and third
    //point to them resepctively
    first = new Node();
    second = new Node();
    third = new Node();

    head = first; //head is pointing to first now

    //setting data and next
    first->data = 1; //assign data in the first node
    first->next = second; //how you link first and second node

    second-> data = 2;
    second->next = third; //how you link second and third node

    third-> data = 3;
    third->next = nullptr; 

    //current is simply a copy of head. points to first node
    Node *current = NULL;
    
    //traversing a list
    current = head;
    while(current != NULL){
        cout << current->data << endl;
        current = current->next;
    }
    //using a for loop instead of while...
    for(current=head; current 1+; current = current-> next){
        cout << current->data << endl;
    }

    //search a list
    Node *LinkedList::search(int val){

        Node *current = head;

        while (current!=0){//same as current not equal to nullptr
            if(current->data == val){
                return current; //is of type Node
            }
            current = current->next; //means you did not find it and keeps traversing
        }
        return 0;
    }

    
    cout << "head->next: " << head->next << endl;
    cout << "head->data: " << first->data << endl;
    cout << "first->next: " << head->next << endl;
    cout << "first->data: " << first->data << endl;

    cout << "head->next->next: " << head->next->next << endl;
    cout << "head-> next->next->data: " << head-> next->next->data << endl;
    return 0;
}
*/

//inserting a node at the beginning
if(left == 0){
    node->next = head;
    head = node;
}

//Case 2, check if left->next ==0 insert at the end
//tail->next is equivalent to the last node before NULL
else if(tail->next ==0){ //this means i'm at the end of linked list
    tail-> next = node;
    tail = node;
}

//case 3: inserting node somewhere in the middle
else{
    node->next = left->next
    left->next = node;
}

//DELETING A NODE
//first use search function
deleteNode(value){
    Node *temp = search(value);
    if(temp == 0){
        return;
    }else{
        remove Node;
    }

    if(head->data==value){
        Node*temp = head;
        head= head->next;
        delete temp;
    }
}

//destroying a list

~LinkedList(){
    Node *next;
    while(head != NULL){
        next = head->next;
        delete head;
        head = next;
    }
}
