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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify result list handling
        ListNode* dummyHead = new ListNode(-1);
        ListNode* current = dummyHead;

        // Pointers for input lists
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;

        int carry = 0;

        // Traverse both lists
        while (ptr1 != nullptr || ptr2 != nullptr) {
            int sum = carry;

            // Add value from first list if available
            if (ptr1 != nullptr) {
                sum += ptr1->val;
                ptr1 = ptr1->next;
            }

            // Add value from second list if available
            if (ptr2 != nullptr) {
                sum += ptr2->val;
                ptr2 = ptr2->next;
            }

            // Create new node with digit and move to next
            current->next = new ListNode(sum % 10);
            carry = sum / 10;  // Update carry
            current = current->next;
        }

        // If there's remaining carry, add it as a new node
        if (carry > 0) {
            current->next = new ListNode(carry);
        }

        // Return the next node of dummy (actual result head)
        return dummyHead->next;
    }
};
