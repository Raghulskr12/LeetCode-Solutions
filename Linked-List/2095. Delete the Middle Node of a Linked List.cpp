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
    ListNode* deleteMiddle(ListNode* head) {
        // If the list is empty or has only one node, return nullptr
        if (head == nullptr || head->next == nullptr)
            return nullptr;

        // If the list has only two nodes, delete the second node
        if (head->next->next == nullptr) {
            head->next = nullptr;
            return head;
        }

        // Count total number of nodes in the list
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        // Calculate the position just before the middle node (0-based index)
        int middleIndex = length / 2;

        // Traverse to the node just before the middle node
        current = head;
        int index = 1; // we stop at (middleIndex - 1), so start from 1
        while (current != nullptr) {
            if (index == middleIndex) {
                // Skip the middle node
                current->next = current->next->next;
                break;
            }
            index++;
            current = current->next;
        }

        return head;
    }
};
