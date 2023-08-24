#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {

  if(head!=nullptr){
    int temp=head->val;
    llpivot(head->next,smaller,larger,pivot);
    if(temp<=pivot){//for smaller
      Node* temp=smaller;
      smaller =head;
      smaller->next =temp;
      head =nullptr;
    }
    if(temp>pivot){ //larger 
      Node* temp =larger;
      larger =head;
      larger->next =temp;
      head =nullptr;
    }
  }
  else{
    larger =nullptr;
    smaller =nullptr;
  }
}