#include <iostream>
using namespace std;


//REFERENCES
/*
int main(){
    int x = 25;
    int &q = x;
    q = 100;
    cout << &x << endl;
    cout << &q << endl;
    cout << "x: " << x << " q: " << q << endl;
    return 0;
}


int main(){
   int a=1;
   int *ptr = &a;
   func(ptr);
   cout << *ptr<< endl;
   return 0; 
}
void func(int *x){
    *x = 3;
    x = 0; //set to null
}


//ASSIGNING POINTERS
int main(){
    int x = 2, y =3; //x contains 2 at add 1000, y contains 3 at add 2000
    int *px=&x, *py=&y, *s; //px contains 1000 at add 3000, py contains 2000 at add 4000
    s=py; //without dereference, put in 's' box what is in py's box, so 2000
    py=px; //1000 replaces 2000 in py's box, redirect pointer to x instead of y
    *px=*py+2;
    //go to where px is pointing, which is to x containing 2
    //go to what py is pointing to and add 2. add 2 which is 4

    cout << x << " " << y << " " << *s << " " << *px << endl;
    return 0;
}


//PASS POINTER TO REFERENCE
//we can pass a reference to a pointer *&
//we can not pass a pointer to a reference &*!!!!!
//we can pass pointers to pointers! (similar to ref to ptr)
//you would want to pass a ptr by ref if you have a need to modify a ptr rather than
//the obj that the pointer is pointing to
//similar to why DP are used
int global = 100;
void func(int *& x){
    *& means create a reference to the pointer we passed in
    //x is a reference to a pointer
    x = &global;
}


int main(){
    int var = 3;
    int *ptr_to_var = &var;
    cout << "Before : " << *ptr_to_var << endl;
    func(ptr_to_var);
    cout << "After : " << *ptr_to_var << endl;
    return 0;
}

//RETURNING POINTERS
int *createArray(){
    static int arr_ca[2];
    //static works, regular int does not work
    //int arr_ca[2];
    arr_ca[0] = 50;
    arr_ca[1] = 100;
    return arr_ca;
}
int main(){
    int *arr = createArray();
    cout << arr[0] << endl;
    cout << arr[1] << endl;
}
//this will not work becaues the array is not global    
//soln = dynamic allocation
//YOU CAN NOT RETURN A PTR TO AN OBJ ALLOCATED ON THE STACK!!
//since it will be destroyed when the function exits!

//an exception is using static int...


//RETURNING POINTERS USING 'NEW'
int *createArray(){
    int *arr_ca = new int[2]; //create on the heap
    arr_ca[0] = 50;
    arr_ca[1] = 100;
    return arr_ca;
}
int main(){
    int *arr = createArray();
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    delete[] arr;
    arr = nullptr;
}
*/

//RETURN REFERENCE TO POINTER

double  *& getNum(){ //returns value of the reference that x is pointing to
    double num = 1000.00;
    static double *x = &num;
    return x;
}
int main(){
    double N = *getNum();
    cout << N << endl;//1000.00 
}
