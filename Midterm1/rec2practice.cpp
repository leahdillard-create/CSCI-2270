#include <iostream>
using namespace std;

int main(){
    int a[] = {1,2,3};
    cout << a+2 << endl; //address at index 2
    cout << &a[2] << endl;
     cout << *(a+2) << endl; //value 3
    cout << *a << endl; //value to first obj which is 1
    //cout << *a[0];

}