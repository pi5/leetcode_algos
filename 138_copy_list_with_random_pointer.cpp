/*    Leetcode: #138
 *    A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 *
 *    Return a deep copy of the list.
 */

#include<iostream>
#include<map>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) return NULL;
    
    RandomListNode *clone = NULL;
    map<RandomListNode *, RandomListNode*> orig_to_clone;

    /* First make a copy of the linked list */
    RandomListNode *temp = head;
    while(temp != NULL) {
        clone = new RandomListNode(temp->label);        
        orig_to_clone[temp] = clone;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        clone = orig_to_clone[temp];    

        /* Update next */
        clone->next = orig_to_clone[temp->next];

        /* Update random */
        if (temp->random != NULL) {
            clone->random = orig_to_clone[temp->random];    
        }
        temp = temp->next;
    }

    return orig_to_clone[head]; 
}

int main() {
    RandomListNode *a = new RandomListNode(1);
    RandomListNode *b = new RandomListNode(2);
    RandomListNode *c = new RandomListNode(3);
    RandomListNode *d = new RandomListNode(4);
    RandomListNode *e = new RandomListNode(5);

    a->next = b; b->next = c; c->next = d; d->next = e;
    a->random = d;
    c->random = e;
    d->random = a; 
}
