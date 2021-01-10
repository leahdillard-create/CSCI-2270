#include "JobQueue.hpp"
#include <iostream>
using namespace std;

JobQueue::JobQueue(){
    queueFront = 0;
    queueEnd = 0;
    counter = 0;
};
  bool JobQueue::isEmpty(){
      if(counter == 0){
          return true;
      }
    return false;
  };
  bool JobQueue::isFull(){
     if(counter==SIZE){
        return true;
    }
    else{
        return false;
    }
  }
  void JobQueue::enqueue(std::string job){
      if(!isFull()){
        queue[queueEnd] = job; //inserts word at 0
        counter++;

        if(queueEnd==SIZE-1){ //handling condition of tail at the end
            queueEnd = 0;
        }
        else{
            queueEnd++; //move tail over an indeces
        }
    }
    else{
        cout << "Queue full, cannot add new job" << endl;
    }
  };
  void JobQueue::dequeue(){
    if(!isEmpty()){
        queue[queueFront];
        counter--;
        if(queueFront==SIZE-1){
            queueFront = 0;
        }
        else{
            queueFront++;
        }
    }
    else{
        cout << "Queue empty, cannot dequeue a job" << endl;
    }

  };
  string JobQueue::peek(){
      if(isEmpty()){
          cout << "Queue empty, cannot peek" << endl;
          return "";
      }
      else{
          return queue[queueFront];
      }
  };
  int JobQueue::queueSize(){
      return counter;
  }; 
 