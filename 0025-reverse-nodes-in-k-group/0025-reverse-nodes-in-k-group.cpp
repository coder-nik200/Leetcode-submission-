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
    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
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

    // Find the kth node starting from temp
    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1; // temp is already pointing to the first node

        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }

        return temp; // Return kth node or nullptr
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while (temp != nullptr) {

            // Find the last node of the current group
            ListNode* kthNode = getKthNode(temp, k);

            // If fewer than k nodes remain, don't reverse them
            if (kthNode == nullptr) {
                if (prev) {
                    prev->next = temp;
                }
                break;
            }

            // Store the starting node of the next group
            ListNode* nextNode = kthNode->next;

            // Disconnect the current group
            kthNode->next = nullptr;

            // Reverse the current group
            reverse(temp);

            // Update head if this is the first group
            if (temp == head) {
                head = kthNode;
            } else {
                // Connect the previous group to the current group
                prev->next = kthNode;
            }

            // Original first node becomes the last node
            prev = temp;

            // Move to the next group
            temp = nextNode;
        }

        return head;
    }
};