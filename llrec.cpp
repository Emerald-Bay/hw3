#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *& head, Node *& smaller, Node *& larger, int pivot)
{
  //Empty linked list
  if (head == nullptr) {
    return;
  }

  llpivot(head->next, smaller, larger, pivot);

  if (head->val > pivot) {
    head->next = larger;
    larger = head;
  }
  else {
    head->next = smaller;
    smaller = head;
  }

  head = nullptr;
  return;
}