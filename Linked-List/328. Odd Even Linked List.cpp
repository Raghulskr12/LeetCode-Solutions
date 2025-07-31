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
    ListNode* oddEvenList(ListNode* head) {
        // ✅ Optimized Approach: In-place rearrangement
        if (!head || !head->next) return head;

        ListNode* odd = head;              // Points to current odd node
        ListNode* even = head->next;       // Points to current even node
        ListNode* evenHead = head->next;   // Save head of even list to append later

        // Rearranging next pointers
        while (even && even->next) {
            odd->next = odd->next->next;   // Skip to next odd node
            even->next = even->next->next; // Skip to next even node

            odd = odd->next;
            even = even->next;
        }

        // Attach even list after odd list
        odd->next = evenHead;
        return head;

        /*
        💡 Brute Force Approach: Using extra space by creating a new list

        // Dummy node for the new rearranged list
        ListNode* resultHead = new ListNode(-1);
        ListNode* resultTail = resultHead;
        int index = 1;
        ListNode* current = head;

        // First pass: Add odd-indexed nodes
        while (current != nullptr) {
            if (index % 2 != 0) {
                resultTail->next = new ListNode(current->val);
                resultTail = resultTail->next;
            }
            current = current->next;
            index++;
        }

        // Second pass: Add even-indexed nodes
        index = 1;
        current = head;
        while (current != nullptr) {
            if (index % 2 == 0) {
                resultTail->next = new ListNode(current->val);
                resultTail = resultTail->next;
            }
            current = current->next;
            index++;
        }

        return resultHead->next;
        */
    }
};
