#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int addToArrayAsc(float sortedArray[], int numElements, float newValue){

    sortedArray[numElements]=newValue;
    float placeholder;

    if(numElements == 0){
        sortedArray[0]=newValue;
        return 1;
    }

    else if(numElements == 100){ //if array is full...
        return numElements+1;
    }

    else{
        for(int i = 0; i< 100; i++){
            for(int x = 0; x < numElements; x++){
                if(sortedArray[x]>sortedArray[x+1]){
                    placeholder = sortedArray[x];
                    sortedArray[x] = sortedArray[x+1];
                    sortedArray[x+1]=placeholder;
                }
            }
        }
    }

    return numElements+1;
}

int main(int argc, char *argv[]){
    int size = 100;
    float arr[size];    

    if(argc != 2){
        cout << "incorrect number of arguments"<< endl;
        return -1;
    }

    else{

        ifstream file;
        file.open(argv[1]);

        if(file.is_open()){
            
            float num;
            int index = 0;

            string line;
            string integers;

            while(getline(file, line)){

                stringstream s(line);

                (getline(s, integers, ','));

                num = stof(integers);

                addToArrayAsc(arr, index, num);
                    
                index++;

                for(int k = 0; k<index; k++){
                    cout << arr[k];
                    if(k!=index-1){
                        cout << ",";
                    }
                }

                cout << endl;
            }
        }

        else{
            cout << "Failed to open the file." << endl;
        }

        file.close();
    }

    return 0;
}