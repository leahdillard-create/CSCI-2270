#include <iostream>
#include <string>
#include <stack>
#include "StackCalculator.hpp"

using namespace std;
/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-")
      return false;

    else if(s.size() > 1 && s[0] == '-')
      s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++){
      if(!isdigit(s[i]) && s[i] != '.')
        return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

StackCalculator::StackCalculator()
{
  stackHead = NULL;
}

StackCalculator::~StackCalculator()
{
  while(!isEmpty()){
      pop();
  }
}

bool StackCalculator::isEmpty()
{
	if(stackHead == NULL){
        return true;
    }
}

void StackCalculator::push(float number)
{
  Operand* node = new Operand;
  node -> number = number;
  node -> next = NULL;
  node->next = stackHead;
  stackHead = node;
}

void StackCalculator::pop()
{
	if(!isEmpty()){
        Operand *node = stackHead;
        stackHead = stackHead->next;
        delete node;
    }
    else{
        cout << "Stack empty, cannot pop an item." << endl;
    }
}

Operand* StackCalculator::peek()
{
	if(!isEmpty()){
        return stackHead;
    }
    else{
        cout << "Stack empty, cannot peek." << endl;
        return nullptr;// remove this line if you want
    }
}

bool StackCalculator:: evaluate(string* s, int size)
{   

  
  /*
    StackCalculator stack;
    
    char ch;
    int operand1, operand2;

    if(stackHead == NULL){
        return 0;
    }
    if(isEmpty()){
            cout << "err: not enough operands" << endl;
            return false;
    }
    else{
      for(int i=size; i >= 0; i--){
      
        if(isNumber(s[i])==true){
          float num = stof(s[i]);
          stack.push(num);
        }
        else if(isNumber(s[i])==false){
            if(s[i]=="+"){
                Operand *num1 = stackHead;
                stack.pop();
                Operand *num2 = stackHead;
                stack.pop();
                int result = *((int*)(&num1))+*((int*)(&num2));
                push(result);
            }
            else if(s[i]=="*"){
                Operand *num1 = stackHead;
                stack.pop();
                Operand *num2 = stackHead;
                stack.pop();
                int result = *((int*)(&num1))*(*((int*)(&num2)));
                push(result);
            }
            else{
                cout << "invalid operator";
            }
            
        }
      }
    }
    */
    return true;
}

