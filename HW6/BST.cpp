/*
//BST traversal
pre order: copy a tree to array, back to tree
in order: ascending order
post order: 

//two types of BST implementations
-iterative
-recursive
*/

#include <iostream>
using namespace std;

struct Node{
    int key;
    Node *left = NULL;
    Node *right = NULL;
};

class BST{
    private:
        Node *root;
        ~BST();
        BST(int data);
        void addNode(int data);
        Node * addNodeHelper(Node *currNode, int data);
        Node *createNode(int data);
        printTree(Node *node)
};

BST::~BST(){
    destroyNode(root);
}

BST::BST(int data){
    root = createNode(data);
    cout << "New tree created with " << data << endl;
}

Node *BST::createNode(int data){
    Node *newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void BST::addNode(int data){
    addNodeHelper(root, data);
    cout << data << " has been added " << endl;
}

Node *BST::addNodeHelper(Node *currNode, int data){
    if(currNode == NULL){ //if there is no pointer
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right, data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left, data);
    }
    //we need to recursively call because we do not know how often we 
    //will have to go down the levels of the tree
    return currNode;
}

void BST::printTreeInOrderHelper(Node*currNode){
    if(currNode){
        printTreeInOrderHelper(currNode->left);
        cout << "" << currNode->key;
        printTreeInOrderHelper(currNode->right);
    }
}

void BST::printTreeInOrder(){
    printTreeInOrderHelper(root);
    cout << endl;
}

Node *BST::searchKeyHelper(Node *currNode, int data){
    if(currNode==NULL){
        return NULL;
    }
    if(currNode->key ==data){
        return currNode;
    }
    if(currNode->key >data){
        return searchKeyHelper(currNode->right,data);
    }
    return searchKeyHelper(currNode->right, data);
}

bool BST::searchKey(int key){
    Node*tree =searchKeyHelper(root,key);
    if(tree!=NULL){
        return true;
    }
    cout<< "key not present in the tree"<<endl;
    return false;
    
}
void BST:: printTree(Node *node){
    if(node==NULL){
        return;
    }
    printTree(node->right);
    printTree(node->left);
    cout<< node->data << endl;
}
/*
void BST::deleteNode(Node *currNode, int value){
    //if the currNode==NULL
    //return NULL
    //else if value < currNode->key
        //currNode->left == deleteNode(currNode->left, value)
    //else if value > currNode->key
    //else node is found that you want to delete...
    //  if left and right children are NULL
    //    else if only right child is null
    //  else if only left child is NULL
    //  else if exists both left and right children
    //return currNode
    if(currNode==NULL){
        return NULL;
    }
    else if(value < currNode->key){
        currNode->left == deleteNode(currNode->left, value);
    }
    else if(value > currNode->key){
        currNode->right = deleteNode(currNode->right, value);
    }
    else{
        if(currNode->left==NULL && currNode->right==NULL){

        }
        else if(currNode->right == NULL){
            Node *temp = currNode;
            currNode = currNode->left; //sets current node to 0
            delete temp;
        }
        else if(currNode->left == NULL){
            Node *temp = currNode;
            currNode = currNode->right; //sets current node to 0
            delete temp;
        }
    }  
}

void BST::removeRange(int low, int high){
    for (int i=low; i<=high;i++){
        root = deleteNode(root,1);
    }
}
*/


