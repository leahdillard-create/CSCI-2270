#include <iostream>
using namespace std;

class BubbleSorting{
    
    public:
        void insertToTempArray(int arr[], int temparr[], int count); //insert method
        void bubbleSortHelper(int &a, int &b); //helper for sort method
        void printArray(int arr[], int length); //display method
        void bubbleSort(int arr[], int length); //sort method
        bool searchArray(int arr[], int length, int numToSearch); //search method
};