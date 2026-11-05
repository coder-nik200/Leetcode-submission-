/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int k) {
        int count = 1;

        while (temp != nullptr) {
            if (count == k)
                return temp;
            count++;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* tail = head;
        int len = 1;

        while (tail->next != nullptr) {
            len++;
            tail = tail->next;
        }

        if (k % len == 0)
            return head;

        k = k % len;

        tail->next = head;

        ListNode* nextNode = findNthNode(head, len - k);

        head = nextNode->next;
        nextNode->next = nullptr;

        return head;
    }
};