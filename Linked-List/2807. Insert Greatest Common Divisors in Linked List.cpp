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
    // Helper function to compute GCD of two numbers
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1); // Dummy node to simplify linking
        ListNode* current = dummy;
        ListNode* temp = head;

        // Traverse until the second last node
        while (temp->next != nullptr) {
            int a = temp->val;
            int b = temp->next->val;

            // Add the current node's value
            current->next = new ListNode(a);
            current = current->next;

            // Insert the GCD between a and b
            current->next = new ListNode(gcd(a, b));
            current = current->next;

            temp = temp->next;
        }

        // Attach the last original node
        current->next = temp;

        return dummy->next;
    }
};
