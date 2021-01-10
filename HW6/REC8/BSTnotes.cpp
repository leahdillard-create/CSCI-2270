//SEARCHING a node
/*
-start with the root and keep moving left or right using the
bst property
-if the data we are searching is the same as node's data, then we return the current node
-if the data we are searching is less than node's data, then search the left
subtree of the current node
-otherwise, search the right subtree of the current node
-if the data is not present, we end up in a null link(that is the leaf node, end of the tree in that branch)
*/

Node *search(Node *node, int search_key){
    if(node==NULL){
        return node;
    }
    if(node->value == search_key){
        return node;
    }
    if(search_key < node->value){
        return search(node->left);
    }
    if(search_key>node->value){
        return search(node->right);
    }
}

Node *found_node_pointer = search(root,5);