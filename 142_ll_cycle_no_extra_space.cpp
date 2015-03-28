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
        ListNode *detectCycle(ListNode *head) {

            if (head == NULL) return NULL;

            /* Without extra space, use runner technique */
            ListNode *fast = head, *slow = head;

            while (fast != NULL && fast->next != NULL) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    break;
                }
            }

            /* If no loop exists */
            if (fast == NULL || fast->next == NULL) {
                return NULL;
            }

            slow = head;
            
            /* Increment fast and slow until we find the loop start */
            while (slow != fast) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;   
        }
};
