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
    // Reverse
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* front = nullptr;
        ListNode* temp = head;

        while (temp != nullptr) {
            front = temp->next;
            temp->next = prev;

            prev = temp;
            temp = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Middle
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverse(slow->next);
        ListNode* secondHalfHead = second;

        ListNode* first = head;

        while (second != nullptr) {
            if (first->val != second->val) {
                second = reverse(secondHalfHead);
                return false;
            }

            first = first->next;
            second = second->next;
        }

        second = reverse(secondHalfHead);

        return true;
    }
};