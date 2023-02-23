#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

// tail approach
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
  if (head==nullptr){
     smaller=nullptr;
     larger=nullptr;
     return;
    }
  else {
    if (head->val <= pivot){
      Node* t = head->next;
      smaller=head;
      smaller->next=nullptr;
      llpivot(t, smaller->next, larger, pivot);
    }
    else{
      Node* t = head->next;
      larger=head;
      larger->next=nullptr;
      llpivot(t, smaller,larger->next, pivot);
    }
    head=nullptr;
  }
  }

