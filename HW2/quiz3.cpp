#include <iostream>
using namespace std;

/*
void add10(int num){
    num = num +10;
}

int main(){
    int a = 10;
    add10(a);
    cout << a << endl;
}


int main(){
    int a = 100, b = 200, c =25;
    int *pa = &a;
    int *pb = &b;
    int *pc = &c;
    b = 50;
    *pc = *pa + *pb;
    pb = pa;
    cout << b << endl;
    cout << *pa << "," << *pb << "," << *pc << endl;
}


#include <iostream>
using namespace std;

int some_num = 19;

void change_pointer(int* ptr){
    ptr = &some_num;
}

int main (){
    int a = 9;
    int *pa = &a;
    change_pointer(pa);
    cout << *pa << endl;
}
*/

int main(){
    int a =5;
    int b = 12;
    int *pa = &a;
    int *pb = &b;
    int *pc;

    pc = pb;
    pb = pa;
    *pc = b+5;
    a = *pb +4;
    cout <<b << endl;
    cout << *pa <<"," << *pb << "," << *pc << endl;
}