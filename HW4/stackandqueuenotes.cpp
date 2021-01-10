#include <iostream>
using namespace std;
#define MAXSIZE 2

struct Node{
    string name;
    Node *next;
};

/*
class Stack{
    private:
        Node *top;
        int count;
    public:
        Stack();
        ~Stack();
        bool isEmpty();
        void push(string newItem);
        void pop();
        Node *peek();
        void disp();
};

//constructor
Stack::Stack(){ //set to null in the constructor
    top = NULL;
}

Stack::~Stack(){ //destructor
    Node *current;
    while(!isEmpty()){
        current = top;
        top = top->next;
        delete current;
    }
}

void Stack::push(string newItem){
    Node *temp = new Node; //we create a new temp pointer
    //Node consists of item and next
    //temp is pointing to address of item
    //when you push the string, it sets the string to the item's 
    temp->name = newItem; //assign input string to name of pointer

    if(isEmpty()){
        top = temp;
        top->next = NULL;
    }
    else{
        temp->next = top;
        top = temp; //sets top equal to top of the stack
    }
}

void Stack::pop(){
    Node *temp;
    if(!isEmpty()){
        temp = top;
        top = top->next;
        delete temp; //you dont delete the pointer itself, it deletes what the pointer is pointing to
    }
    else{ //if stack is empty an error message will appear
        cout << "underflow, stack empty" << endl;
    }
}

bool Stack::isEmpty(){
    if(top==NULL){
        return true;
    }
    else{
        return false;
    }
}

Node *Stack::peek(){
    return top;
}

void Stack::disp(){
    Node *current = top;
    cout << "Top of the stack: " << endl;
    while(current != NULL){
        cout << current->name << endl;
        current = current->next;
    }
    cout << endl;
}
*/

class StackArr{
    private:
        int top, count;
        string a[MAXSIZE]; //will only store 2 strings
    public:
        StackArr();
        bool isFull();
        void push(string newItem);
        void disp();
        string pop();
};

StackArr::StackArr(){ 
    top = 0;
}

bool StackArr::isFull(){
    if(top ==MAXSIZE){
        return true;
    }
    else{
        return false;
    }
}

void StackArr::push(string newItem){
    if(!isFull()){
        a[top]= newItem;
        top++;
    }
    else{
        cout << "Stack OVerflow:" << endl;
    }
}

string StackArr::pop(){
    string out;
    if(!isFull()){
        out = a[--top]; //increment back one
    }
    else{
        cout << "Stack is empty" << endl;
        out = "";
    }
}

void StackArr::disp(){
    cout << "top = " << top << endl;
    for(int i = top-1; i >=0; i--){
        cout << a[i] << endl;
    }
}

int main(){
    StackArr s;
    s.push("Casey");
    s.push("Claudia");
    s.push("Chase");
    s.push("Adam");
    s.pop(); //no parameters will delete "Adam"
    s.pop(); //no parameters will delete "Chase"
    s.disp();
}

//QUEUES
/*
-similar to queue at a bank or grocery store
-commonly used in computer simulation, CPU and disk scheduling, print spooling, call center phone systems
-First-In First-Out (FIFO) data structure
-Queue can use circular arrays, simple arrays, and linked lists
    >CIRCULAR ARRAYS
    -there isn't an end to the queue and elements are added or deleted in a circular motion
    -the last position (last node) is connected back to the first position (first node) to make a circle

-dequeing removes from the FRONT
-enqueing adds to the BACK
if all spots are full linearly, since it is a circle enqueue will add to front
*/