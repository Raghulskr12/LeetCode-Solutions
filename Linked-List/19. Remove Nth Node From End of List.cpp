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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count total number of nodes in the list
        ListNode* current = head;
        int totalNodes = 0;
        while (current != nullptr) {
            totalNodes++;
            current = current->next;
        }

        // Step 2: If list has only one node, return NULL after deletion
        if (totalNodes < 2) return NULL;

        // Step 3: If the node to remove is the head (n == total count)
        if (n == totalNodes) {
            ListNode* newHead = head->next;
            delete head; // free memory
            return newHead;
        }

        // Step 4: Traverse to the node just before the one to delete
        int targetPosition = totalNodes - n;
        current = head;
        int currentIndex = 1;
        while (currentIndex < targetPosition) {
            current = current->next;
            currentIndex++;
        }

        // Step 5: Remove the nth node from end
        ListNode* nodeToDelete = current->next;
        current->next = current->next->next;
        delete nodeToDelete; // free memory

        return head;
    }
};
