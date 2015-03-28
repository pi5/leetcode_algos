/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */
class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {

            if (head == NULL) return NULL;

            /* Find the first node with value greater than or equal to x */
            struct ListNode *p = head, *before = NULL, *after = NULL;
            while(p != NULL && p->val < x) {
                before = p;
                p = p->next;
            }

            /* Partitioning is not possible */
            if (p == NULL) return head;

            after = p;

            /* Traverse until the end of the list and reposition the out of place node */

            while (after!=NULL && after->next != NULL) {
                if (after->next->val >= x) {
                    after = after->next;
                }
                else {
                    struct ListNode* temp = after->next->next;

                    /* Case when partitioning happens at head; update head */
                    if (p == head) {
                        head = after->next;
                        head->next = p;
                        after->next = temp;
                        before = head;
                    }
                    else {
                        before->next = after->next;
                        before = before->next;
                        before->next = p;
                        after->next = temp;
                    }
                }
            }
            return head;
        }
};
