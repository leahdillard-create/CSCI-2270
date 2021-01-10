#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *next;

    Node(){
        key = -1;
        next = NULL;
    }
    Node(int data){
        key = data;
        next = NULL;
    }
    Node(int data, Node*next_){
        key = data;
        next = next_;
    }
};

class LinkedList{
    private:
        Node *head;
        Node *tail;
    public:
        LinkedList(); //constructor
        ~LinkedList(); //destructor
        void traverse();
        void display();
        void createnode(int value);
        Node*search(int value);
        void insertnode(int left, int value);
        void deletenode(int value);
        bool lengthIsEven();
        Node* deleteNegatives();
        void move();
};

LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
}

LinkedList::~LinkedList(){
    Node *next;
    while(head!=NULL){
        next = head->next;
        delete head;
        head = next;
    }
    cout << "deleted" << endl;
}

void LinkedList::createnode(int value){
    Node *temp = new Node;
    temp->key = value;
    temp->next = NULL;
    if(head==NULL){
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

void LinkedList::traverse(){
    Node *current = head;
    while(current !=NULL){
        cout << current->key << "->";
        current = current->next;
    }
    if(current==NULL){
        cout << "NULL" << endl;
    }
    cout << endl;
}

void LinkedList::display(){
    Node *temp = new Node;
    temp = head;
    while(temp!=NULL){
        cout << temp->key << "->";
        temp = temp->next;
    }
    cout << endl;
}

Node* LinkedList::search(int value){
    Node *current = head;
    while(current!=NULL && current->key!=value){
        current = current->next;
    }
    return current;
}

void LinkedList::insertnode(int left, int value){
    Node *node = new Node(value);
    Node *leftNode = search(left);

    if(leftNode == NULL){
        node->next = head;
        head = node;
    }
    else if(leftNode->next==NULL){
        tail->next = node;
        tail = node;
    }
    else{
        node->next = leftNode->next;
        leftNode->next = node;
    }
}

void LinkedList::deletenode(int value){
    Node *temp = search(value);
    if(temp == NULL){
        return;
    }
    else{
        if(head->key==value){ //delete head node
            temp = head;
            head = head->next;
            delete temp;
        }
        else{
            Node *left = head;
            Node *temp = left->next;
            bool isFound = false;
            
            while(temp !=NULL && isFound !=true){
                if(temp->key == value){
                    if(temp->next == NULL){//for tail node
                        left->next = NULL;
                        tail = left;
                    }
                    else{
                        left->next = temp->next; //for middle node
                    }
                    delete temp;
                    isFound = true;
                }
                else{
                    left = temp;
                    temp = temp->next;
                }  
            }
        }
    } 
} 

bool LinkedList::lengthIsEven(){
    int count = 0;
    Node *current = head;
    while(current!=NULL){
        current = current->next;
        count++;
    }

    if(count%2==0){
        return true;
    }
    
    else{
        return false;
    }
}

Node* LinkedList::deleteNegatives(){
    Node *current = head;
    Node *prev = NULL;

        while(current!=NULL){
            if(current->key<0){
                if(current==head){
                    head=head->next;
                    delete current;
                    current = head;
                }
                else{
                    prev->next=current->next;
                    delete current;
                    current = prev->next;
                }
            }
            else{
                prev = current;
                current = current->next;
            }
        }
    return head;
}

void LinkedList::move(){
    Node*temp = head->next;
    Node* temp2 = new Node;
    temp2 = temp->next;
    Node* temp3= new Node;
    temp3= temp2->next;
    temp3->next = temp2;
    temp2->next = temp3->next;
    temp->next = temp3;
    delete temp2;
    temp2 = NULL;
    delete temp3;
    temp3=NULL;
    delete temp;
    temp = NULL;
}


int main(){

    LinkedList list;
    
    list.createnode(1);
    list.createnode(3);
    list.createnode(9);
    list.createnode(8);
    list.createnode(14);
    list.createnode(15);
    list.traverse();
    list.move();

    /*
    if(!list.deleteNegatives()){
        list.display();
        cout << "negatives were not deleted" << endl;
    }
    else{
        list.display();
        cout << "negatives were deleted" << endl;
    }

    //CHECK TO SEE IF THE LIST IS EVEN
    if(!list.lengthIsEven()){
        cout << "Length is odd" << endl;
    }
    else{
        cout << "Length is even" << endl;
    }
    
    //list has 5,2,8,40
    list.display();
    list.traverse();

    cout << endl;

    //search for a number in the list
    if(!list.search(2)){
        cout << "not found" << endl;
    }
    else{
        cout << "found" << endl;
    }

    cout << endl;

    //Search for number not in the list
    if(!list.search(33)){
        cout << "not found" << endl;
    }
    else{
        cout << "found" << endl;
    }

    cout << endl;

    //ADD 3 and 9 to the list
    list.insertnode(5,3);
    list.insertnode(3,9);
    list.display();
    
    cout << endl;

    //DELETE 3 from list
    list.deletenode(3); //pass 3 into the function
    list.display(); //print list without 3

    list.~LinkedList(); //should print "deleted"
    list.display(); //should print "deleted"
    */
}