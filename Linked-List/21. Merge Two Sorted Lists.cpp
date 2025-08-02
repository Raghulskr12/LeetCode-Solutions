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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode(-1); // Dummy node
        ListNode* ansd = ans;             // Head of the result list

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                ans->next = list1;
                ans = ans->next;
                list1 = list1->next;
            }
            else if (list1->val > list2->val) {
                ans->next = list2;
                ans = ans->next;
                list2 = list2->next;
            }
            else {
                // When both values are equal, include both
                ans->next = list1;
                ans = ans->next;
                list1 = list1->next;

                ans->next = list2;
                ans = ans->next;
                list2 = list2->next;
            }
        }

        if (list1) ans->next = list1;
        if (list2) ans->next = list2;

        return ansd->next;
    }
};
