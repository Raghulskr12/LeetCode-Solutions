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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> removeSet(nums.begin(), nums.end());

        // Remove all leading nodes that need to be deleted
        while (head != nullptr && removeSet.find(head->val) != removeSet.end()) {
            head = head->next;
        }

        // Now head is either null or a valid node to keep
        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (removeSet.find(current->next->val) != removeSet.end()) {
                current->next = current->next->next; // Skip the node
            } else {
                current = current->next; // Move forward
            }
        }

        return head;
    }
};
