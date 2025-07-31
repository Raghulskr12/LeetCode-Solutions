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
    ListNode* reverseList(ListNode* head) {
        // Base cases
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        // Iterative reversal
        while (curr != nullptr) {
            nextNode = curr->next;  // Store next node
            curr->next = prev;      // Reverse current node's pointer
            prev = curr;            // Move prev and curr forward
            curr = nextNode;
        }

        return prev; // New head of the reversed list
    }
};
