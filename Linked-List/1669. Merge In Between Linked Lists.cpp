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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prevA = nullptr;  // Node before position a
        ListNode* afterB = nullptr; // Node after position b

        ListNode* curr = list1;
        int pos = 0;

        // Traverse list1 to find prevA and afterB
        while (curr != nullptr) {
            if (pos == a - 1) prevA = curr;
            if (pos == b + 1) {
                afterB = curr;
                break;
            }
            curr = curr->next;
            pos++;
        }

        // Link prevA to start of list2
        prevA->next = list2;

        // Traverse to end of list2
        ListNode* tail2 = list2;
        while (tail2->next != nullptr) {
            tail2 = tail2->next;
        }

        // Link tail of list2 to afterB
        tail2->next = afterB;

        return list1;
    }
};
