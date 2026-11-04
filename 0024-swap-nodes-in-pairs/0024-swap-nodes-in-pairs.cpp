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
    ListNode* reverse(ListNode* temp) {
        ListNode* prev = nullptr;
        ListNode* front = nullptr;

        while (temp != nullptr) {
            front = temp->next;
            temp->next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr && temp->next != nullptr) {
            ListNode* nextNode = temp->next->next;

            temp->next->next = nullptr;

            ListNode* newHead = reverse(temp);

            if (prev == nullptr) {
                head = newHead;
            } else {
                prev->next = newHead;
            }

            prev = temp;
            temp = nextNode;

            if (temp != nullptr) {
                prev->next = temp;
            }
        }

        return head;
    }
};