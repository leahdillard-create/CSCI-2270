struct BSTNode{
    int data;
    BSTNode *left;
    BSTNode *right;
};

BSTNode *root;
root = NULL;

BSTNode* insert(BSTNode* root, int data){
    if(root == NULL){
        root = GetNewNode(data);
        return root;
    }
    else if(data<=root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

bool Search(BSTNode* root, int data){
    if(root == NULL){
        return false;
    }
    else if(root->data == data){
        return true;
    }
    else if(data <= root->data){
        return Search(root->left, data);
    }
    else{
        return Search(root->right,data);
    }
}

int main(){
    BSTNode *root = NULL;
    Insert(root, 15);
    Insert(root, 10);
    Insert(root, 20);
}

BSTNode * GetNewNode(int data){
    BSTNode *newNode = new BSTNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}