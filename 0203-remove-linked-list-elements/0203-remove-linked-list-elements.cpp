/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(NULL) {}
 *     ListNode(int x) : val(x), next(NULL) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;

        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            if (temp->val == val) {
                ListNode* curr;

                if (prev == NULL) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }

                temp = temp->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};