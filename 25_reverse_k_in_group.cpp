/*
 *    Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 *
 *    If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 *
 *    You may not alter the values in the nodes, only nodes itself may be changed.
 *
 *    Only constant memory is allowed.
 *
 *    For example,
 *    Given this linked list: 1->2->3->4->5
 *
 *    For k = 2, you should return: 2->1->4->3->5
 *
 *    For k = 3, you should return: 3->2->1->4->5
 */


#include <iostream>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

void print (ListNode *head) {
    cout << endl;
    while(head!=NULL) {
        cout << head->val << "-->";    
        head = head->next;
    }
    cout << endl;
}

ListNode* getnext (ListNode* head, int &k) {
    
    while (k != 0 && head!=NULL) {
        head = head->next;
        k--;    
    }    
    return head;
}

ListNode* reverse_until (ListNode *head, ListNode *end) {
    if (head == NULL) return NULL;
    ListNode *curr = head, *prev = NULL, *next;    
    
    while(curr!=NULL && curr!=end) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


ListNode *reverseKGroup(ListNode *head, int k) {
    
    if (head == NULL) return NULL;

    ListNode *curr = head, *prev = NULL, *next, *subhead;

    while (curr != NULL) {
        int x = k;
        next = getnext(curr, x);

        /* We reverse sublist only we cover entire group of k */ 
        if(x==0) {
            subhead = reverse_until (curr, next);
        }
        else {
            subhead = curr;    
        }
        
        if (prev == NULL) {
            head = subhead;
        }
        else{
            prev->next = subhead;    
        }

        prev = curr;
        curr = next;
    }
    
    return head;
}



int main() {

   ListNode *a = new ListNode(1); 
   ListNode *b = new ListNode(2); 
   ListNode *c = new ListNode(3); 
   ListNode *d = new ListNode(4); 

   a->next = b; b->next = c; c->next = d;// d->next = e;
   print(a);
   a = reverseKGroup(a, 2);
   print(a);
    
}

