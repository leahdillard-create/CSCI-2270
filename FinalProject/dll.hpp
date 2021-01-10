#include <iostream>
using namespace std;

struct Node{ //dll template
    int key;
    Node *next;
    Node *prev;
};

class DoubleLink{

    private:
        Node *tail; //pointer to tail of linked list
        Node *head; //pointer to the head of the linked list

    public:
        DoubleLink(); //default constructor
        ~DoubleLink(); //destructor
        Node* searchDLL(int insertValue); //search method
        void insertLastDLL(int insertValue); //insert method
        void insertFirstDLL(int insertValue);
        void displayDLL(); //display method
};