/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode* current = head;

        while (current != nullptr) {
            if (visited[current]) {
                return current; // First node in the cycle
            }
            visited[current] = true;
            current = current->next;
        }

        return nullptr; // No cycle
    }
};
