#include <iostream>
#include "QueueLL.hpp"

using namespace std;

QueueLL::QueueLL()
{
    queueFront = nullptr;
    queueEnd = nullptr;
}

QueueLL::~QueueLL()
{
    while( !isEmpty() )
        dequeue();
}

bool QueueLL::isEmpty()
{
    if(queueFront == nullptr || queueEnd == nullptr)
        return true;
    return false;
    return (!queueFront || !queueEnd);
}

// TODO
void QueueLL::enqueue(int key)
{
    Node *nn = new Node;
    nn->key = key;
    nn->next = nullptr;

    if(queueEnd==NULL && queueFront==NULL){
        queueFront=queueEnd=nn;
        return;
    }

    queueEnd->next = nn;
    queueEnd=nn;
}

//TODO
void QueueLL::dequeue()
{
    Node *to_be_deleted = queueFront;
    
    if(!isEmpty())
    {
        if(queueFront == NULL){
            queueEnd = NULL;
        }
        queueFront = queueFront->next;
        delete to_be_deleted;
        return;
    }

    else{
        cout<<"queue is empty. can not deque"<<endl;
        return;
    }
}
   

int QueueLL::peek()
{
    if( !isEmpty() )
        return queueFront->key;
    else
    {
        cout<< " queue is empty. can not peek"<<endl;
        return -1;
    }
    //return 0;
}
