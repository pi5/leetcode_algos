#include<iostream>
using namespace std;


struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

/* Recursively */
ListNode *swapPairs(ListNode *head) {

    if (head == NULL || head->next == NULL) return head;
    
    ListNode *next_head = swapPairs(head->next->next); 
    ListNode *temp = head->next;
    temp->next = head;
    head->next = next_head;
    return temp;
}

/* Iteratively while replacing node data */

ListNode *swapPairs_iterative(ListNode *head) {
    
    if (head == NULL || head->next == NULL) return head;

    bool copied = false;
    int data;
    ListNode *temp = head;
    while(head != NULL && head->next!=NULL) {
        data = head->val;
        head->val = head->next->val;
        head->next->val = data;
        head = head->next->next;            
    }

    return temp;

}

void printList (ListNode*head) {
    cout << endl;
    while(head!=NULL) {
        cout << head->val << " --> ";
        head = head->next;         
    }    
    cout << endl;
}


int main() {
    
    ListNode *head = new ListNode(1);
    ListNode *p = head;

    for (int i = 1; i < 10; i++) {
        p->next = new ListNode(i+1);
        p = p->next;    
    }
    
    printList(head);
    head = swapPairs(head);
    printList(head);
    head = swapPairs(head);
    head = swapPairs_iterative(head);
    printList(head);
    
}
