#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *& head, Node *& smaller, Node *& larger, int pivot)
{
  smaller = nullptr;
  larger = nullptr;

  //Empty linked list
  if (head == nullptr) {
    return;
  }

  //Value is less than/equal to pivot
  if (head->val <= pivot) {
    smaller = head;
  } //Value is greater than
  else {
    larger = head;
  }

  //Last node head the list
  if (head->next == nullptr) {
    head = nullptr;
    return;
  }

  llpivot_helper(head->next, smaller, larger, pivot);

  //Original list is not preserved
  head = nullptr;
  return;
}

void llpivot_helper(Node *& head, Node *& smaller, Node *& larger, int pivot) {
  bool smallerFlag = true;
  bool largerFlag = true;

  //Value is less than/equal to pivot
  if (head->val <= pivot) {
    if (smaller == nullptr) {
      smaller = head;
    }
    else {
      smaller->next = head;
      smallerFlag = false;
    }
  } //Value is greater than
  else {
    if (larger == nullptr) {
      larger = head;
    }
    else {
      larger->next = head;
      largerFlag = false;
    }
  }

  //Last node head the list
  if (head->next == nullptr) {
    if (largerFlag && larger != nullptr) {
      larger->next = nullptr;
    }

    if (smallerFlag && smaller != nullptr) {
      smaller->next = nullptr;
    }

    return;
  }

  //Ensures first addition does not mess up later addition
  llpivot_helper(head->next, smallerFlag ? smaller : smaller->next, largerFlag ? larger : larger->next, pivot);
}


