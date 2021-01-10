#include <iostream>
#include <fstream>
#include <chrono>
#include "hashquad.hpp"
using namespace std;

int main(){

    using namespace std::chrono;

    int index = 0; 
    int tableSize = 40009;
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
    
    ofstream outputFile("insert_search_performance_hashquad_dataSetA.csv");
    if(outputFile.is_open()){ //open output file

        float insert[100]; //array to keep track of insert time
        float search[100]; //array to keep track of search time
        int counter = 100; //increase for loop by 100 every time
        int randomNumIncrement = 100; //between 1-99; 1-199; 1-299; etc.

        HashTable ht(tableSize); //create hashtable of 40009
        
        for(int i = 0; i < 100; i++){ //iterate 100 times
            
            //INSERT
            auto startInsert = chrono::steady_clock::now(); //start timer
            for(int j = 0; j < counter; j++){
                ht.insert(testData[j]); //insert up to index 100, then 200, then 300, etc.
            }
            auto endInsert = chrono::steady_clock::now(); //end timer
            
            cout << "Time in nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(endInsert-startInsert).count() << " ns" << endl;
            insert[i] = (duration_cast<nanoseconds>(endInsert-startInsert).count())/100; //write to insert array
            cout << "insert[" << i << "]: " << insert[i] << endl; 
            outputFile << insert[i] << " , "; //write to output file


            //SEARCH
            int randomNum = rand() % randomNumIncrement; //generate a set of 100 pseudo random nums on interval of [0,99]
            int input = testData[randomNum]; //random num values as indeces into test data array

            auto startSearch = chrono::steady_clock::now(); //start timer
            for(int j = 0; j < counter; j++){
                ht.search(input); //search number we find at index
            }
            auto endSearch = chrono::steady_clock::now(); //end timer

            cout << "Time in nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(endSearch-startSearch).count() << " ns" << endl;
            search[i] = (duration_cast<nanoseconds>(endSearch-startSearch).count())/100; //write to search array
            cout << "search[" << i << "]: " << search[i] << endl; 
            outputFile  << search[i] << " , "; //write to output

            //COLLISION
            int collisions = ht.getNumOfCollision();
            cout << "Collisions: " << collisions << endl;
            outputFile << collisions << endl; //Write collisions to output file           

            counter+=100; //increment counter by 100
            cout << endl; 
        } 
        //ht.printTable();
    }
    
    outputFile.close(); 

    return 0;
}