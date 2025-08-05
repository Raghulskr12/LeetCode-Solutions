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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head; // No rotation needed
        }

        // Step 1: Compute the length of the list
        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Step 2: Connect the last node to the head to make it circular
        tail->next = head;

        // Step 3: Find the new tail position: (length - k % length) steps from head
        k %= length;
        int stepsToNewTail = length - k;

        // Step 4: Move to the new tail
        while (stepsToNewTail--) {
            tail = tail->next;
        }

        // Step 5: Break the circle and set new head
        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};
