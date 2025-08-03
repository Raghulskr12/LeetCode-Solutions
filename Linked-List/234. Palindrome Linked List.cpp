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
    bool isPalindrome(ListNode* head) {
        stack<int> valueStack;
        ListNode* current = head;

        // Push all values to the stack (stores in reverse order)
        while (current != nullptr) {
            valueStack.push(current->val);
            current = current->next;
        }

        current = head;

        // Compare original list with reversed values from stack
        while (current != nullptr) {
            if (current->val != valueStack.top()) {
                return false; // Mismatch found, not a palindrome
            }
            valueStack.pop();
            current = current->next;
        }

        return true; // All values matched
    }
};
