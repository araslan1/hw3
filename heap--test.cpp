#include <iostream>
#include <string>
#include "heap.h"
using namespace std; 

int main(){
  Heap<int> a;
  a.push(0);
  a.push(5);
  a.push(10);
  cout << a.top() << endl;
  a.pop();
  cout << a.top() << endl;
  a.pop();
  cout << a.top() << endl;
  a.pop();
}