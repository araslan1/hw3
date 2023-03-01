#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  larger = nullptr; 
  smaller = nullptr; 
  if (head  !=NULL){
    if (head->val > pivot){
      larger = head;
      Node* update = head->next; 
      // head = nullptr; 
      llpivot(update, smaller, larger->next, pivot);
    }else {
      smaller = head; 
      Node* update = head->next; 
      // head = nullptr; 
      llpivot(update, smaller->next, larger, pivot);
    }
  }
  head = nullptr; 
}

