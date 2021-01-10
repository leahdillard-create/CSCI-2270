#include <iostream>
using namespace std;
#define MAXSIZE 5
class StackArr{
    private:
        int top, count;
        int a[MAXSIZE]; //will only store 2 strings
    public:
        StackArr();
        bool isFull();
        void push(int newItem);
        void disp();
        void pop();
};

StackArr::StackArr(){ 
    top = 0;
}

bool StackArr::isFull(){
    if(top ==MAXSIZE){
        return true;
    }
    else{
        return false;
    }
}

void​ ​StackArr::push​(​int​ value) {
​if​(!isFull()) {
data[top] = value;
top = top + ​1​; }
}

void​ StackArr::​pop​() {
if​(top == ​0​) {
 cout<< ​"underflow error"​; }
else{
top = top - ​1​;
}
return​ data[top] }

void StackArr::disp(){
    cout << "top = " << top << endl;
    for(int i = top-1; i >=0; i--){
        cout << a[i] << endl;
    }
}

int main(){
    StackArr s;
    s.push(19);
    s.pop();
    s.push(4);
    s.push(5);
    s.pop();
    s.push(16);
    s.push(1);
    s.pop();
    s.disp();
}
