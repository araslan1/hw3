#include <iostream>
#include "stack.h"
using namespace std;

int main(){
  Stack<int> a; 
  a.push(2); 
  cout << a.top() << endl; 
}