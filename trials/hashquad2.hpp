#include <iostream>
#include <list>

using namespace std;

class hashTable{
    private:
        list<int> *table;
        int tableSize;
    public:
        hashTable(int size);
        int hashFunction(int key);
        void insertIntoTable(int insertValue);
        bool searchTable(int searchValue);
        void printTable();
};


