#include "queArrCir.hpp"
#include <iostream>
#include "string"
using namespace std;

int main(){
    
    QueArrCir q0;
    q0.enque("6");
    q0.enque("12");
    q0.enque("77");

    string s;
    s = q0.deque();
    cout << s << endl;

    q0.enque("14");

    s = q0.deque();
    cout << s << endl;

    s = q0.deque();
    cout << s << endl;

    q0.enque("22");
    q0.enque("40");
    q0.enque("92");

    s = q0.deque();
    cout << s << endl;

//no stack or queue coding question!!

    return 0;
}