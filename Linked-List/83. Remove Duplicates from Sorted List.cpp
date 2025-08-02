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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        // ✅ Main logic: In-place removal of duplicates from a sorted list
        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;  // Skip duplicate
            } else {
                temp = temp->next;  // Move forward
            }
        }

        return head;

        /*
        🔁 Alternate approach (if list is unsorted):
        - Use a set to collect unique elements
        - Rebuild a new list from the set
        - Note: This does NOT preserve the original order

        set<int> store;
        ListNode* star = new ListNode(-1);  // Dummy head for new list
        ListNode* star1 = star;
        ListNode* temp = head;

        // Step 1: Store all unique values
        while (temp != nullptr) {
            store.insert(temp->val);
            temp = temp->next;
        }

        // Step 2: Create new list from the set
        for (auto it : store) {
            ListNode* arr = new ListNode(it);
            star->next = arr;
            star = star->next;
        }

        return star1->next;
        */
    }
};
