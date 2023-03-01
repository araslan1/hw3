#include <iostream>
#include "llrec.h"
using namespace std; 


int main(){
  Node* a = new Node(4, nullptr); 
  Node* head = new Node(5, a);
  Node* large = nullptr; 
  Node* small = nullptr; 
  llpivot(head, small, large, 4); 
  cout << large->val << endl;
  cout << small->val << endl; 
  
}