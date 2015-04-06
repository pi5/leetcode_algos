/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.

*/

#include<iostream>
using namespace std;

struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};


ListNode* reverse_list (ListNode *head) {
    if(head == NULL) return NULL;    

    ListNode *prev = NULL, *curr = head, *next;
    
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;    
    }
    return prev;
}


void reorderList(ListNode *head) {
    if(head == NULL) return;

    /* First we find the middle of the linked list */            
    ListNode *slow = head, *fast = head, *mid;

    while(fast != NULL && fast->next != NULL) {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;    
    }

    /* If number of nodes are odd, step forward by one */
    if (fast!=NULL) {
        mid = slow;
        slow = slow->next;    
    }

    /* mid now points to element before the middle of the linked list */
    /* we break the linked list and reverse the second half */
    mid->next = NULL;
    slow = reverse_list(slow);

    /* Now we merge the two lists */
    mid = head;
    while(slow != NULL) {
        ListNode *temp1 = mid->next;
        ListNode *temp2 = slow->next;
        mid->next = slow;
        slow->next = temp1;
        slow = temp2;
        mid = temp1;
    }
}


void printList (ListNode *head) {
    while (head != NULL) {
        cout << head->val << "-->";
        head = head->next;    
    }    
    cout << endl;
}

int main() {
    
    ListNode *head = new ListNode(1);
    ListNode *temp = head;

    for(int i = 2; i < 9; i++) {
        temp->next = new ListNode(i);    
        temp = temp->next;
    }

    printList (head);
    reorderList(head);
    printList(head);
}
