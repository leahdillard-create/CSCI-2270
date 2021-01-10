#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
// MovieNode: node struct that will be stored in the MovieTree BST
MovieNode* getMovieNode(int rank, string t, int y, float r) {
    MovieNode* nn = new MovieNode;
    nn->title = t;
    nn->ranking = rank;
    nn->year = y;
    nn->rating = r;
    return nn;
}

void deleteHelper(MovieNode *node){
  if(node ==NULL){
    return;
  }
  deleteHelper(node->left);
  deleteHelper(node->right);
  delete node;
  node = NULL;
}

MovieTree::MovieTree() {
    root = NULL;
}

MovieTree::~MovieTree() {
  deleteHelper(root);
}

void printInventoryHelper(MovieNode *temp){
  if(temp==NULL){
    return;
  }

  printInventoryHelper(temp->left);
  cout << "Movie: " << temp->title << " " << temp->rating << endl;
  printInventoryHelper(temp->right);
}

void MovieTree::printMovieInventory() {
   printInventoryHelper(root);
   if(root==NULL){
     cout << "Tree is Empty. Cannot print" << endl;
   }
}

void addHelper(MovieNode *root, MovieNode *temp){
  if(temp -> title < root->title){
    if(root->left != NULL){
      addHelper(root->left, temp);
    }
    else{
      root->left = temp;
    }
  }
  else{
    if(root->right != NULL){
      addHelper(root->right,temp);
    }
    else{
      root->right=temp;
    }
  }
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  MovieNode *temp = new MovieNode;

  temp->rating = rating;
  temp->ranking = ranking;
  temp->title = title;
  temp->year = year;
  temp->left = NULL;
  temp->right = NULL;

  if(root == NULL){
    root = temp;
  }
  else{
    addHelper(root, temp);
  }
}

void findMovieHelper(MovieNode* currentNode, string s){
    if(currentNode==NULL){
      cout << "Movie not found." << endl;
      return;
    }
    if(currentNode->title == s){
      cout << "Movie Info:"<<endl;
      cout <<"==================" << endl;
      cout << "Ranking:" << currentNode->ranking << endl;
      cout << "Title  :" << currentNode->title << endl;
      cout << "Year   :" << currentNode->year << endl;
      cout << "rating :" << currentNode->rating << endl;
    }
    else if(currentNode->title > s){
      findMovieHelper(currentNode->left, s);
    }
    else{
      findMovieHelper(currentNode->right,s);
    }
}
void MovieTree::findMovie(string title) {
  findMovieHelper(root, title);
}

void queryMovieHelper(MovieNode *movie, float rating, int year){
  if(movie==NULL){
    return;
  }
  if(movie->year>=year && movie->rating >= rating){
    cout << movie->title << "(" << movie->year << ") " << movie->rating << endl;
  }
  queryMovieHelper(movie->left, rating, year);
  queryMovieHelper(movie->right, rating, year);
}
void MovieTree::queryMovies(float rating, int year) {
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  queryMovieHelper(root, rating, year);
}

double averageRatingHelper(MovieNode*temp){
  if(temp==NULL){
    return 0;
  }
  return temp->rating + averageRatingHelper(temp->right)+averageRatingHelper(temp->left);
}

double averageRatingHelperNode(MovieNode*temp){
  if(temp==NULL){
    return 0;
  }
  return 1+ averageRatingHelperNode(temp->right)+averageRatingHelperNode(temp->left);
}

void MovieTree::averageRating() {
  if(root==NULL){
    cout << "Average rating:0.0" << endl;
  }
  else{
    cout << "Average rating:" << averageRatingHelper(root)/averageRatingHelperNode(root)<<endl;
  }
}

void printLevelNodesHelper(MovieNode *movie, int level){
  if(movie==NULL){
    return;
  }
  if(level==0){
    cout << "Movie: " << movie->title << " " << movie->rating << endl;
  }
  else if(level>0){
    printLevelNodesHelper(movie->left, level-1);
    printLevelNodesHelper(movie->right, level-1);
  }
}
void MovieTree::printLevelNodes(int k) {
  //write your code
  printLevelNodesHelper(root, k);
}
