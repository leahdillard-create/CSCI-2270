//dynamic memory allocation

//on heap memory, variables dont get names! they only get addresses

//in static memory allocation using stacks, variable is removed from stack
//as soon as thefunction in which it was decalred terminates

//delete operator

#include <iostream>
using namespace std;

int main(){
    int *p1;
    p1 = new int;
    *p1 = 100;
    cout << p1 << endl;
    cout << *p1 << endl;
    delete p1;

    return 0;
}

/*
LINKED LISTS
   - a linked list is a linear data structure, in which the elements 
    are not stored at contiguous memory locations.
    - every element in a linked list is called a "node"
    - have no predefined size!
    */



