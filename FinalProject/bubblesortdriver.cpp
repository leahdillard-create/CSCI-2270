#include <iostream>
#include <chrono>
#include <fstream>
#include "bubblesort.hpp"
using namespace std;

int main(){

    using namespace std::chrono;

    int index = 0;
    int testData[10000]; //array for length of data file
    char output[10000]; //convert to char in order to read into new array

    //Reading test data into testData array of size 10000
    ifstream myFile;
    myFile.open("dataSetA.csv");
    if(myFile.is_open()){ //if file is able to be open
        while(myFile >> output && !myFile.eof()){ //while the file is steraming into char output array and is not at the end
            testData[index] = atoi(output); //test data at index is converted to int value and stored
            index++; //increment size by 1, indexing through entire file
        }
    }
    else{
        cout << "ERROR: Input file can not be opened." << endl;
        return -1; //end program if file can not be opened
    }
    myFile.close(); //close file 

    BubbleSorting b; //declare class value

    ofstream outputFile("sort_performance_bubblesort_dataSetA.csv");
    if(outputFile.is_open()){ //open output file
        float sort[100]; //array for sort time measurement
        int n = 100; //initialize incrementing variable at 100
        
        for(int i = 0; i < 100; i++){ //iterate 100 times
            
            int tempArr[n]; //declare a temp array of size 100, 200, 300...10,000.
            
            //INSERT from testData array to a temporary array
            b.insertToTempArray(testData, tempArr, n);
            
            //cout << "Pre-sorted: ";
            //b.printArray(tempArr, n);

            //SORT items in tempArr
            auto startSort = chrono::steady_clock::now(); //start time before array runs to get time of first 100 inserts
            b.bubbleSort(tempArr,n);
            auto endSort = chrono::steady_clock::now(); //end timer
            
            cout << "Sorting time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(endSort-startSort).count() << " ns" << endl;
            sort[i] = duration_cast<nanoseconds>(endSort-startSort).count()/100; //insert to sort array
            cout << "sort[" << i << "]: " << sort[i] << endl;
            outputFile << sort[i] << " " << endl;

            //cout << "After sorted: ";
            //b.printArray(tempArr, n);

            n +=100; //increment n by 100 each time so we get 100, 200, 300...10,000. 

            cout << endl;
        }       
    }
    outputFile.close();//close output file

    return 0;
}