#include <iostream>
using namespace std;

struct Node {
  int key;
  Node *next;
  Node *head;
  Node(){
    head = NULL;
    }
};



int main(){

Node *pres = head;

int count = 0;
while(pres!= NULL && count < 2) {
        if(pres->key == 2) {
            count = count + 1;
        }
        pres = pres->next;
}
cout <<  pres->key  << endl;
}
