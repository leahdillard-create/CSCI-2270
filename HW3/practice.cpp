#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class list{
    private: 
        Node *head;
        Node *tail;
    public:
        list(){
            head = NULL;
            tail = NULL;
        }
        void createnode(int value);
        void display();
};

void list::createnode(int value){

    Node *temp = new Node;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{ //link with tail node
        tail->next=temp;
        tail=temp;
    }
}

int main(){
    
}

