#include <iostream>
#include <fstream>
#include "MovieTree.hpp"

using namespace std;

LLMovieNode* getLLMovieNode(int r, std::string t, int y, float q)
{
	LLMovieNode* lmn =new LLMovieNode();
	lmn->ranking = r;
	lmn->title=t;
	lmn->year =y;
	lmn->rating =q;
	lmn->next =NULL;
	return lmn;
}
/* ------------------------------------------------------ */
MovieTree::MovieTree()
{
	root = NULL;
}
/* ------------------------------------------------------ */

void deleteHelper(TreeNode *&node){
  if(node ==NULL){
    return;
  }
  deleteHelper(node->leftChild);
  deleteHelper(node->rightChild);
  LLMovieNode *top = node->head;
  while(top!=NULL){
        LLMovieNode *target = top;
        top = top->next;
        delete target;
        target = NULL;
  }
  delete node;
  node = NULL;
}

MovieTree::~MovieTree(){
    deleteHelper(root);
}

void showMovieCollectionHelper(TreeNode *temp){
	if(temp!=NULL){
		showMovieCollectionHelper(temp->leftChild);
		cout << "Movies starting with letter: " <<temp->titleChar << endl;
		LLMovieNode *m = temp->head;
		while(m!=NULL){
			cout << " >> " << m->title << " " << m->rating << endl;
			m = m->next;
		}
		showMovieCollectionHelper(temp->rightChild);
	}
}

void MovieTree::showMovieCollection(){
	showMovieCollectionHelper(root);
}

void _grader_inorderTraversal(TreeNode * root) {
		if (root == NULL) {
			return;
		}

		_grader_inorderTraversal(root->leftChild);
		cout << root->titleChar << " ";
		_grader_inorderTraversal(root->rightChild);
}

void MovieTree::inorderTraversal() {
	_grader_inorderTraversal(root);
	cout << endl;
}

TreeNode* searchCharHelper(TreeNode* curr, char key)
{
    if (curr == NULL)
        return curr;
    else if(curr->titleChar == key)
        return curr;
    else if (curr->titleChar > key)
        return searchCharHelper(curr->leftChild, key);
    else
        return searchCharHelper(curr->rightChild, key);
}

TreeNode* MovieTree::searchCharNode(char key)
{
    return searchCharHelper(root, key);
}

TreeNode *insertInTree(TreeNode *&root, string title, TreeNode *parent){
    if(root ==NULL){
        TreeNode *temp = new TreeNode;
        temp->head = NULL;
        temp->leftChild=NULL;
        temp->rightChild=NULL;
        temp->parent=parent;
        temp->titleChar=title[0]; //set title Char to the first letter of title
        root = temp;
        return root;
    }
    else if(root->titleChar>title[0]){
        return insertInTree(root->leftChild,title,root);
    }
    else{
        return insertInTree(root->rightChild,title,root);
    }
}

void insertInList(LLMovieNode *&top, LLMovieNode *node){
    if(top==NULL){
        top = node;
        return;
    }
    if(top->title>node->title){
        node->next=top;
        top=node;
    }
    else{
        LLMovieNode *previous = top;
        for(LLMovieNode *i = top->next; i!=NULL; i=i->next){
            if(i->title>node->title){
                node->next = i;
                previous->next = node;
                return;
            }
            previous = i;
        }
        previous->next = node;
    }
}
void MovieTree::insertMovie(int ranking, std::string title, int year, float rating){
    LLMovieNode *node = new LLMovieNode;
    node->next=NULL;
    node->ranking = ranking;
    node->title = title;
    node->year = year;
    node->rating = rating;
    
    TreeNode *temp = searchCharHelper(root, title[0]);

    if(temp==NULL){
        insertInList(insertInTree(root,title,NULL)->head, node);
    }
    else{
        insertInList(temp->head,node);
    }
}

void searchNode(TreeNode *&temp1, TreeNode *&temp2){
    if(temp2->leftChild!=NULL){
        searchNode(temp1,temp2->leftChild);
    }
    else{
        temp1->titleChar=temp2->titleChar;
        temp1->head = temp2->head;
        temp1->parent=temp1->parent;
        temp1=temp2;
        temp2=temp2->rightChild;
    }
}

void removeMovieRecordHelper(TreeNode *&temp, char intake){
    if(temp==NULL){
        return;
    }
    else{
        if(intake< temp->titleChar){
            removeMovieRecordHelper(temp->leftChild, intake);
        }
        else if(intake > temp->titleChar){
            removeMovieRecordHelper(temp->rightChild, intake);
        }
        else{
            TreeNode *node = temp;
            if(temp->leftChild == NULL){
                if(temp->rightChild != NULL){
                    temp->rightChild->parent=temp->parent;
                }
                temp = temp->rightChild;
            }
            else if(temp->rightChild==NULL){
                if(temp->leftChild != NULL){
                    temp->leftChild->parent=temp->parent;
                }
                temp = temp->leftChild;
            }
            else{
                searchNode(node,temp->rightChild);
            }
            delete node;
            node = NULL;
        }
    }
}

void MovieTree::removeMovieRecord(std::string title){
    char searchTitle = title[0];
    TreeNode *node = searchCharHelper(root, searchTitle);

    if(node!=NULL && node->head!=NULL){
        if(node->head->title==title){
            LLMovieNode *temp = node->head;
            node->head = node->head->next;
            delete temp;
            temp = NULL;
        }
        else{
            LLMovieNode *previous = node->head;
            for(LLMovieNode *top = node->head->next; top!=NULL; top = top->next){
                if(top->title==title){
                    LLMovieNode *temp = top;
                    previous->next=top->next;
                    delete temp;
                    temp = NULL;
                    break;
                }
                previous = top;
            }
        }
        if(node->head==NULL){
            removeMovieRecordHelper(root, node->titleChar);
        }
        return;
    }
}

void MovieTree::leftRotation(TreeNode* curr){
    TreeNode *temp = curr->rightChild;
    if(curr->titleChar == root->titleChar){
       curr->rightChild = temp->leftChild;
       temp->leftChild=curr;
       temp->parent = NULL;
       curr->parent=temp;   

       if(curr->rightChild!=NULL){
           curr->rightChild->parent=curr;
       }
       root = temp;
       return;                                               
    }
    if(curr->parent->rightChild->titleChar==curr->titleChar){
        curr->parent->rightChild = temp;
    }
    else{
        curr->parent->leftChild = temp;
    }

    temp->parent = curr->parent;
    curr->parent = temp;
    curr->rightChild = temp->leftChild;

    if(temp->leftChild!=NULL){
        temp->leftChild->parent=curr;
    }
    temp->leftChild=curr;
}
/*
LLMovieNode *insertMovieHelper(LLMovieNode *node, LLMovieNode *&temp){
    if(temp == NULL){
        return node;
    }
    if(node->title < temp->title){
        TreeNode* left = insertMovieHelper(temp->leftChild, node);
        temp->leftChild = left;
        left->parent = temp;
    }
    else if(node->titleChar > temp->titleChar){
        TreeNode* right = insertMovieHelper(temp->rightChild, node);
        temp->rightChild = right;
        right->parent = temp;
    }
    else if(node->titleChar==temp->titleChar){
        LLMovieNode *insertNode = node->head;
        LLMovieNode *current = temp->head;
        LLMovieNode *previous = NULL;
        while(current!=NULL && current->title.compare(insertNode->title)<0){
            previous = current;
            current = current->next;
        }
        if(current!= NULL && current->title.compare(insertNode->title)==0){
            return temp;
        }
        else{
            if(previous == NULL){
                insertNode->next = temp->head;
                temp->head=insertNode;
            }
            else if(current ==NULL){
                previous->next = insertNode;
            }
            else{
                previous->next = insertNode;
                insertNode->next = current;
            }
        }
    }
    return temp;
}
void MovieTree::insertMovie(int ranking, std::string title, int year, float rating){
    LLMovieNode *movie = getLLMovieNode(ranking,title,year,rating);
    TreeNode *index = new TreeNode;

    if(root==NULL){
        root = index;
        root->head = movie;
        root->head->next = NULL;
        return;
    }
    TreeNode *parent = NULL;
    TreeNode *temp = root;

    while(temp!=NULL){
        parent = temp;
        if(index->titleChar < temp->titleChar){
            temp = temp->leftChild;
        }
        else if(index->titleChar == temp->titleChar){
            index = temp;
            break;
        }
        else{
            temp= temp->rightChild;
        }
    }

    if(index->head == NULL){
        index->head = movie;
        index->head->next = NULL;
    }

    else{
        int count = 1;
        LLMovieNode *current = index->head;
        while(current!=NULL){
            while(current->title[count]==movie->title[count]){
                count++;
                if(count == current->title.length()){
                    if(current->next ==NULL){
                        current->next = movie;
                        movie->next = NULL;
                        count = 1;
                        return;
                    }
                    else{
                        current=current->next;
                        count = 1;
                    }
                }
                else if(count == movie->title.length()){
                    if(current == index->head){
                        movie->next = index->head;
                        index->head = movie;
                        return;
                    }
                    else{
                        LLMovieNode *previous = NULL;
                        LLMovieNode *temp = index->head;
                        while(temp != current){
                            previous = temp;
                            temp = temp->next;
                        }
                        movie->next = current;
                        previous->next = movie;
                        return;
                    }
                }
            }
            if(current->title[count]<movie->title[count]){
                if(current->next==NULL){
                    current->next = movie;
                    movie->next = NULL;
                    count = 1;
                    return;
                }
                else{
                    current = current->next;
                    count = 1;
                }
            }
            else if(current->title[count] > movie->title[count]){
                if(current==index->head){
                    movie->next = index->head;
                    index->head = movie;
                    return;
                }
                else{
                    LLMovieNode *previous = NULL;
                    LLMovieNode *temp = index->head;
                    while(temp != current){
                        previous = temp;
                        temp = temp->next;
                    }
                    movie->next = current;
                    previous->next = movie;
                    return;
                }
            }        
        }
    }
    return;
}


TreeNode* traverseTree(TreeNode* node, string title){
    
    char letter = title[0];
    if(node == NULL){
        return 0;
    }
    else if(node->titleChar == letter){
        return node;
    }
    else if(node->titleChar>letter){
        return traverseTree(node->leftChild, title);
    }
    else{
        return traverseTree(node->rightChild,title);
    }
}
LLMovieNode *traverseLL(LLMovieNode* node, string title){
    if(node==NULL){
        return 0;
    }
    else if(node->title == title){
        return node;
    }
    else{
        return traverseLL(node->next, title);
    }
}

TreeNode *helper2(TreeNode *node){
    TreeNode * i = node;
    while(i->leftChild != NULL){
        i = i->leftChild;
    }
    return i;
}

void MovieTree::removeMovieRecord(std::string title){
    TreeNode *node = traverseTree(root,title);
    
    if(node==NULL){
        cout << "Movie not found." << endl;
        return;
    }
    LLMovieNode *movie = traverseLL(node->head, title);
    if(movie == NULL){
        cout << "Movie not found." << endl;
        return;
    }
    else if((movie==node->head)&&(node->head->next==NULL)){
        node->head=NULL;
        delete(movie);
        return;
        if((node->leftChild==NULL)&&(node->rightChild==NULL)){
            if(node->parent==NULL){
                delete(node);
                return;
            }
            else if(node->parent->leftChild==node){
                node->parent->leftChild=NULL;
                delete(node);
                return;
            }
            else if(node->parent->rightChild==node){
                node->parent->rightChild=NULL;
                delete(node);
                return;
            }
        }
        else if(node->leftChild==NULL){
            node->rightChild->parent = node->parent;
            if(node->parent==NULL){
                root = node->rightChild;
                delete(node);
                return;
            }
            else if(node->parent->rightChild==node){
                node->parent->rightChild=node->rightChild;
                delete(node);
                return;
            }
        }
        else if(node->rightChild==NULL){
            if(node->parent==NULL){
                root = node->leftChild;
                delete(node);
                return;
            }
            else if(node->parent->rightChild=node){
                node->parent->rightChild=node->leftChild;
                delete(node);
                return;
            }
        }
        else{
            TreeNode *minimum = helper2(node->rightChild);

            if(minimum==node->rightChild){
                minimum->leftChild = node-> leftChild;
                node->leftChild->parent = minimum;

                if(node->parent==NULL){
                    root = minimum;
                    delete(node);
                    return;
                }
                else if(node == node->parent->leftChild){
                    minimum->parent = node->parent;
                    node->parent->leftChild = minimum;
                    delete(node);
                    return;
                }
                else if(node == node->parent->rightChild){
                    minimum->parent=node->parent;
                    node->parent->rightChild=minimum;
                    delete(node);
                    return;
                }
            }
            else{
                minimum->parent->leftChild=minimum->rightChild;
                minimum->rightChild->parent = minimum->parent;
                minimum->leftChild = node->leftChild;
                minimum->rightChild = node->rightChild;
                minimum->leftChild->parent = minimum;
                minimum->rightChild->parent = minimum;

                if(node->parent==NULL){
                    root = minimum;
                    delete(node);
                    return;
                }
                else if(node->parent->leftChild==node){
                    minimum->parent = node->parent;
                    node->parent->leftChild=minimum;
                    delete(node);
                    return;
                }
                else if(node->parent->rightChild==node){
                    minimum->parent = node->parent;
                    node->parent->rightChild=minimum;
                    delete(node);
                    return;
                }
            }
        }
    }
    else{
        if(node->head == movie){
            node->head = movie->next;
            delete(movie);
            return;
        }
        LLMovieNode *previous = NULL;
        LLMovieNode *temp = node->head;
        while(temp!=movie){
            previous = temp;
            temp = previous->next;
        }

        previous->next = movie->next;
        delete(movie);
        return;
    }
    return;
}
*/