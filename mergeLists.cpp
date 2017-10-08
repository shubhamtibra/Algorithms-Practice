

/*
  Merge two sorted lists A and B as one linked list
  Node is defined as
*/

#include< iostream>

using namespace std;

typedef struct Node
  {
     int data;
     struct Node *next;
  } Node;

Node* MergeLists(Node *headA, Node* headB)
{
    if (headA == NULL) return headB;
    if (headB == NULL) return headA;
    
    Node *head = NULL, *tail = NULL;
    if(headA->data < headB->data) {
        head = headA;
        tail = headA;
        headA = headA->next;
        
    }
    else{
        head = headB;
        tail = headB;
        headB = headB->next;
    }
    while( headA != NULL || headB != NULL){
        if(headA == NULL) {
            tail->next = headB;
            return head;
        }
        if (headB == NULL){
            tail->next = headA;
            return head;
        }
        if (headA->data < headB->data){
            tail->next = headA;
            tail = tail->next;
            headA = headA->next;
        }
        else{
            tail->next = headB;
            tail = tail->next;
            headB = headB->next;
        }
    }
    return head;
}
