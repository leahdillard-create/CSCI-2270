#include <iostream>
#include "heapsort.hpp"
using namespace std;

HeapSorting::HeapSorting(){ //initialize size and heap

    size = 0;
    heap = NULL;
}

void HeapSorting::insertToTempArray(int arr[], int temparr[], int length){

    for(int i = 0; i<length; i++){ //copy values from array to temporary array 
        temparr[i] = arr[i];
        //cout << "index "<< i << " copied: " << temparr[i] << endl;
    }
}

int HeapSorting::parent(int i){ //return int value of parent of i
    return (i-1)/2;
}

int HeapSorting::leftChild(int i){ //return int value of left child of i
    return 2*i + 1;
}

int HeapSorting::rightChild(int i){ //return int value of right child of i
    return 2*i + 2;       
}

void HeapSorting::swapArrValues(int *x, int *y){ //swap pointers with temp variable
    
    int temp = *x;
    *x = *y;
    *y = temp;
}

void HeapSorting::insert(int insertData){ //insert into heap
    
    size++; //increment size

    int *temp = new int[size]; //pointer of new int size

    for(int i = 0; i < size - 1; i++){ //copy from temp array to heap array
        temp[i] = heap[i];
    }

    temp[size-1] = insertData; //temp at index is equal to insertData
    delete[] heap; //delete heap array
    heap = temp; //set heap to temp array 
}

void HeapSorting::heapSort(int arr[], int heapSize){ //sort heap

    size = heapSize; //initialize size to input
    int num = size; //set num value to this size

    createHeap(arr,heapSize); //create heap from input array and size

    for (int i = num - 1; i >= 1; i--) { //get one element from heap at a time

        swapArrValues(&arr[0], &arr[i]); //move root to the end 
        heapSize -= 1; //decrease heapsize by 1
        maxHeapify(arr, 0, heapSize); //plug into maxHeapify function
    }
}
 
void HeapSorting::createHeap(int arr[], int heapSize){ //create heap with input values

    //first index of non-leaf node to root
    for(int i = (size-1)/2; i>= 0; i--){ //plug in array values at index to maxHeap
        maxHeapify(arr, i, heapSize);
    }

    return; //end
}

void HeapSorting::maxHeapify(int arr[], int i, int heapSize){

    int left = leftChild(i); //create an int variable for the left child
    int right = rightChild(i); //cerate a int variable for right child
    int max = 0; //initialize max value as the root

    if(left < heapSize && arr[left] < arr[i]){ //if left is bigger than max
        max = left; //set max to left 
    }
    else{ //otherwise, max is equal to index value;
        max = i;
    }

    if(right < heapSize && arr[right] < arr[max]){ //if right value is larger than max
        max = right; //set max value to right child
    }

    if(max!=i){ //if max is not the root
        
        swapArrValues(&arr[i], &arr[max]); //swap values
        maxHeapify(arr, max, heapSize); //recursively call function
    }

    return; //break out of function
}

void HeapSorting::displayHeapArr(int arr[], int num){ //print contents of maxHeap in order

    for(int i = 0; i < num; i++){ //traverse array and print
        cout << arr[i] << " ";
    }
    
    cout << endl;
}
