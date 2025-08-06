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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr; // Empty list
        if (!head->next) return head; // Only one node, return as-is

        ListNode* prev = head;
        ListNode* curr = head->next;

        // Dummy node to store the result list
        ListNode* resultHead = new ListNode(-1);
        ListNode* resultTail = resultHead;

        // Check the first node separately
        if (head->val != head->next->val) {
            resultTail->next = new ListNode(head->val);
            resultTail = resultTail->next;
        }

        // Traverse the list
        while (curr->next != nullptr) {
            if (prev->val == curr->val || curr->val == curr->next->val) {
                // Duplicate found, skip
                prev = curr;
            } else {
                // Unique node, add to result
                prev = curr;
                resultTail->next = new ListNode(curr->val);
                resultTail = resultTail->next;
            }
            curr = curr->next;
        }

        // Handle the last node separately
        if (curr->val != prev->val) {
            resultTail->next = new ListNode(curr->val);
            resultTail = resultTail->next;
        }

        return resultHead->next; // Skip dummy node
    }
};
