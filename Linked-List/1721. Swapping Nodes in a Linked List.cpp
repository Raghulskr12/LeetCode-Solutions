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
    ListNode* swapNodes(ListNode* head, int k) {
        // Pointers and variables for traversing and storing values
        ListNode* temp = head;
        int valueFromStart = 0;
        int valueFromEnd = 0;
        int currentPosition = 1;
        int length = 0;

        // Step 1: Calculate the total length of the linked list
        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }

        // Step 2: Calculate the position from the start for the k-th node from the end
        int kthFromEndPosition = length - k + 1;

        // Step 3: Traverse again to store the values at k-th and kth-from-end nodes
        temp = head;
        currentPosition = 1;
        while (temp != nullptr) {
            if (currentPosition == k) {
                valueFromStart = temp->val;
            }
            if (currentPosition == kthFromEndPosition) {
                valueFromEnd = temp->val;
            }
            temp = temp->next;
            currentPosition++;
        }

        // Debug output (can be removed in production)
        cout << valueFromStart << endl;
        cout << valueFromEnd << endl;

        // Step 4: If values are same, swapping not needed
        if (valueFromStart == valueFromEnd) return head;

        // Step 5: Traverse again and update the node values
        temp = head;
        currentPosition = 1;
        while (temp != nullptr) {
            if (currentPosition == k) {
                temp->val = valueFromEnd;
            }
            if (currentPosition == kthFromEndPosition) {
                temp->val = valueFromStart;
            }
            temp = temp->next;
            currentPosition++;
        }

        return head;
    }
};
