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
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int totalNodes = 0;

        // Step 1: Count the total number of nodes in the list
        while (current != nullptr) {
            totalNodes++;
            current = current->next;
        }

        // Step 2: Find the middle index (0-based)
        int middleIndex = totalNodes / 2;

        // Step 3: Traverse again to the middle node
        current = head;
        int index = 0;
        while (index < middleIndex) {
            current = current->next;
            index++;
        }

        // Step 4: Return the middle node
        return current;
    }
};
