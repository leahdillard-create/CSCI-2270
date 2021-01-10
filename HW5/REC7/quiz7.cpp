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
        findSum(TreeNode * root, int depth);
};
int BST::findSum(TreeNode * root, int depth)
{
    if(root != NULL)
    {
       int leftSum = findSum(root->left, depth + 1);
       int rightSum = findSum(root->right, depth + 1);
       cout << root->key;
       if (depth != 0)
       {
          cout << " ";
       }
       return leftSum + rightSum + root->key;
    }
    else {
       return 0;
    }
}

int main(){
    Node *root = 
    findSum(root, 0);
}