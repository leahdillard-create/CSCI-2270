#ifndef HASH_HPP
#define HASH_HPP

using namespace std;

struct hashNode{ //node template
    int key;
    int value;
    struct hashNode *next;
};

class HashTable
{
    private:
        int tableSize; 
        hashNode* *table;
        int numOfCollision;

    public:
        HashTable(int bsize);  // Constructor
        ~HashTable();//deconstructor
        unsigned int hashFunction(int key);// hash function to map values to key
        hashNode* addNode(int key, hashNode*next);
        void insert(int key);// inserts a key into hash table
        hashNode* search(int key);  //search for a node with matching key
        int getNumOfCollision(); //return number of collisions
        void printTable(); //print table
};

#endif