#include <iostream>
using namespace std;

class hashTable{
    private:
        int tableSize;
    public:
        hashTable(int inputSize);
        int hashFunction(int key);
        void quadraticHash(int t[], int arr[], int num);
        void printTable(int arr[], int size);

};