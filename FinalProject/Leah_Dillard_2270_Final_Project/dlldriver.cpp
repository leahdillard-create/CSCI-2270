#include <iostream>
#include <fstream>
#include <chrono>
#include "dll.hpp"
using namespace std;

int main(){

    using namespace std::chrono; 

    int index = 0; 
    int testData[10000]; //array for length of data file
    char output[10000]; //array to take in char input in order to transfer csv file to testData

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

    DoubleLink dl; 
    ofstream outputFile("insert_search_performance_DLL_dataSetA.csv");

    if(outputFile.is_open()){   

        float insert[100]; //array to keep track of insert time
        float search[100]; //array to keep track of search time
        int counter = 100; //used for counter incrementation
        int randomNumIncrement = 100; //used for random number generator incrementation

        for(int i = 0; i < 100; i++){ //loop through 100 times
            
            //INSERT
            auto startInsert = chrono::steady_clock::now(); //start time before array runs to get time of first 100 inserts
            for(int j = 0; j < counter; j++){ //increment array by upperbound of 100 every time we run (100,200,300...10,000)
                dl.insertLastDLL(testData[j]); //call function in class, insert at index
            }
            auto endInsert = chrono::steady_clock::now(); //end timer
            
            cout << "Time in nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(endInsert-startInsert).count() << "  ns" << endl;
            insert[i] = duration_cast<nanoseconds>(endInsert-startInsert).count()/100; //insert count into array
            cout << "insert[" << i << "]: " << insert[i] << endl;
            outputFile  << insert[i] << " , ";

            //SEARCH
            int randomNum = rand() % randomNumIncrement; //generate a set of 100 pseudo random nums on interval of [0,99], then [0,199], etc.
            int input = testData[randomNum]; //random num values as indeces into test data array
            
            auto startSearch = chrono::steady_clock::now(); //start timer
            for(int j = 0; j < counter; j++){
                dl.searchDLL(input); //search number we find at index in the DLL
            }
            auto endSearch = chrono::steady_clock::now(); //end timer

            cout << "Time in nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(endSearch-startSearch).count() << " ns" << endl;
            search[i] = duration_cast<nanoseconds>(endSearch-startSearch).count()/100;
            cout << "search[" << i << "]: " << search[i] << endl;
            outputFile  << search[i] << endl;
            
            counter += 100; //increment counter
            randomNumIncrement+=100; //increment randomNum boundary

            cout << endl;
        }       
    }

    //dl.displayDLL();
    outputFile.close(); //close file

    return 0;
}