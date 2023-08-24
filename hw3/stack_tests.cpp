#include <iostream>
#include "stack.h"
using namespace std;

int main(){
  Stack<int> myStack;
  int a = int(1);
  int b = int(2);
  int c = int(3);
  int d = int(4);
  int e = int(5);
  myStack.push(a);
  myStack.push(b);
  myStack.push(c);
  myStack.push(d);
  myStack.push(e);
  cout<<"top should be 5: "<<myStack.top()<<endl;
  myStack.pop();
  cout<<"top should be 4: "<<myStack.top()<<endl;
  
  cout<<"empty should be 0 " << myStack.empty()<<endl;
  

  return 0;
}
/*
g++ -g -Wall --std=c++11   stack.h
c++ -g -Wall --std=c++11  -o stack_tests stack_tests.cpp
*/