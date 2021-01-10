#include <iostream>
#include <chrono>
#include <fstream>
#include "heapsort.hpp"
using namespace std;

int main(){

    using namespace std::chrono;

    int index = 0; //initialize index to 0
    int testData[10000]; //array for length of data file
    char output[10000]; //convert to char in order to read into new array

    //Reading test data into testData array of size 10000
    ifstream myFile;
    myFile.open("dataSetA.csv");

    if(myFile.is_open()){ //if file is open

        while(myFile >> output && !myFile.eof()){//while file is not at the end as it streams to output array
            testData[index] = atoi(output); //write testData as integers
            index++; //increment for each index
        }
    }
    else{ 

        cout << "ERROR: Input file can not be opened." << endl;
        return -1; //end program if file can not be opened
    }

    myFile.close(); //close file 

    HeapSorting h; 

    ofstream outputFile("sort_performance_heap_dataSetA.csv");
    if(outputFile.is_open()){ //open output file

        float sort[100]; //array for sort time measurement
        int count = 100; //initialize count to start at 100

        for(int i = 0; i < 100; i++){
            
            int tempArr[count]; //create a temparray with size of count that can be incremented

            //INSERT from testData array to a temporary array
            h.insertToTempArray(testData, tempArr, count);

            //SORT items in tempArr
            auto startSort = chrono::steady_clock::now(); //start time before array runs to get time of first 100 inserts
                h.heapSort(tempArr, count);
            auto endSort = chrono::steady_clock::now(); //end timer

            cout << "Sorting time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(endSort-startSort).count() << " ns" << endl;
            sort[i] = duration_cast<nanoseconds>(endSort-startSort).count()/100; //write to sort array 
            cout << "sort[" << i << "]: " << sort[i] << endl;
            outputFile << sort[i] << " " << endl; //stream to output file

            //cout << "After sorted: ";
            //h.displayHeapArr(tempArr, count);

            count +=100; //increment count

            cout << endl;
        }       

    }
    outputFile.close(); //close output file

    return 0;
}