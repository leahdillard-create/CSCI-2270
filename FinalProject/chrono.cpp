#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>

using namespace std;

//C++ program to find the execution time of code
int main(){

    using namespace std::chrono;
    auto start = chrono::steady_clock::now();

    //assume i am timing bubble sort
    //what you want to time goes in here
    //call to bubble sort

    this_thread::sleep_for(std::chrono::seconds(4));

    auto end = chrono::steady_clock::now();

    cout << "Elapsed time in nanoseconds : " << chrono::duration_cast<chrono::nanoseconds>(end-start).count() << " ns" << endl;

    cout << "Elapsed time in microseconds : " << chrono::duration_cast<chrono::microseconds>(end-start).count() << " ns" << endl;

    cout << "Elapsed time in milliseconds : " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << " ns" << endl;

    //insert the calculation into sort[0]
    //use milliseconds, nanoseconds, microseconds,etc to see which one works best

    int sort[100];
    sort[0] = duration_cast<microseconds>(end-start).count();
    cout << "sort[0]: " << sort[0] << endl;
    return 0;

}