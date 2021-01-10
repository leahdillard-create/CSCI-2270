#include <iostream>
using namespace std;

struct Node{
    int info;
    Node *next;
};

bool lengthIsEven(Node *head){

    Node *temp = head;
    int count;

    if(temp == NULL){
        return false;
    }
    while(temp!=NULL){
        temp = temp->next;
        count++;
    }

    if(count%2==0){
        return true;
    }
    else{
        return false;
    }
}

void display(Node *node){
    while(node!=NULL){
        cout << node->info << "->";
        node = node->next;
    }
}

void create()

int main(){

    Node *listA=;

    if(lengthIsEven(listA)){
        cout << "length is even " << endl;
    }
    else{
        cout << "length is odd" << endl;
    }

}

