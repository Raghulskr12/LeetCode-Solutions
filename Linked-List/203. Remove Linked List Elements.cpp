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
    ListNode* removeElements(ListNode* head, int val) {
        // Edge case: if list is empty
        if (head == nullptr) return nullptr;

        ListNode* current = head;

        // Traverse the list and skip nodes with the target value (except head)
        while (current->next != nullptr) {
            if (current->next->val == val) {
                // Skip the node by pointing to the next of next
                current->next = current->next->next;
                continue;
            }
            current = current->next;
        }

        // After processing rest of list, handle if head itself needs to be removed
        if (head->val == val) {
            ListNode* newHead = head->next;
            delete head; // free the removed head node
            return newHead;
        }

        return head;
    }
};
