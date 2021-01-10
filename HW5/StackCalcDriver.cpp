#include<iostream>
#include<cmath>
#include <string>
#include<iomanip>
#include "StackCalculator.hpp"

using namespace std;

bool isNumber(string s);
int main()
{
  // stack to hold the operands
  StackCalculator stack;

  int numElement = 0;
  int i = 0;
  string* inparr = new string[50];

  // enter a number
  string number;
  cout << "Enter the operators and operands ('+', '*') in a prefix format" << endl;

  while(number != "=")
  {
    cout << "#> ";
    getline(cin, number);
    
    inparr[i] = number;

      /*
      else if(!isNumber(number)){
        
      }
      */
  
    numElement++;
  }
    /*
     TODO
       1. Read input (operators and operands) until you encounter a "="
       2. store them in inparr
    */
  stack.evaluate(*inparr,50);

  if(stack.isEmpty()){
    cout << "No operands: Nothing to evaluate" << endl;
    return 0;
  }

  /* TODO - If the inparr is empty then print "No operands: Nothing to evaluate"
            else call the evaluate function
  */

  Operand *temp = stack.peek();
  float result = temp->number;
  stack.pop();
  if(!stack.isEmpty()){
    cout << "err: invalid operation" << endl;
  }
  else{
    cout << "Result= " << result << endl;
  }
  delete inparr;
  inparr = NULL;

  /* TODO - Validate the expression
      1. If valid then print the result cout << "Result= "<<result << endl;
      2. Else, print "Invalid expression"*/
 
  return 0;
}

