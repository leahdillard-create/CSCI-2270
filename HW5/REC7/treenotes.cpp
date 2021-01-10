/*
TREE
tree is a hierarchial or non-linear data structure
    unlike arrays, linked lists, stacks and queues which are linear

BINARY TREES
-each node has at most two children, it has two pointers that point to the left and right
child of that node
-the root of a tree is the node with no parents. every tree has only one root node
-a node with no children or NULL children is called a leaf node

RECURSION
-a recursive function is a function that calls itself during its execution
-this enables the function to repeat itself several times,
outputting the result(if needed) at the end of each iteration
-having a termination criterion for recursive function is important

TREE TRAVERSAL
-in order to do any operation on trees, we need a mechanismfor visiting nodes
of the tree data structure
-the process of visiting all nodes of a tree is called tree traversal
-linear data strucutres like linked lists, stacks and queues 
-three main methods
    -pre order
    -in order
    -post order

-pre order
    -visit current node
    -traverse left subtree of current node 
    -traverse right subtree of current node
-in order
    -traverse left subtree of current node i.e. call inOrder(left subtree)
    -visit current node
    -traverse right subtree i.e. call inOrder(right subtree)

-post order
    -traverse the left subtree or current node, i.e. call postorder(left subtree)
    -traverse the right subtree of current node, i.e. call postorder (right subtree)
    -visit current node

-common errors
    -always check if node is NULL or not
    
*/

//implementation:
struct treeNode{
    int data;
    treeNode *left;
    treeNode *right;
};

treeNode *node = new treeNode;

void printPreOrder(treeNode *node){
    if(node==NULL){
        return;
    }
    //first print data of node
    cout << node->data << " ";
    //then recur on left subtree
    printPreOrder(node->left);
    //recur on right subtree
    printPreOrder(node->right);
}

void printInOrder(treeNode *node){
    if(node == NULL){
        return;
    }
    //first recur on the left child
    printInOrder(node->left);
    //print data of node
    cout << node->data << " ";
    //then recur on right child
    printInOrder(node->right);
}

void printPostOrder(treeNode *node){
    if(node==NULL){
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << endl;
}
