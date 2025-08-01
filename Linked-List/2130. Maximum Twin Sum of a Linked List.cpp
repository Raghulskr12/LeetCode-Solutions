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
    int pairSum(ListNode* head) {
        // Edge case: only two nodes
        if (head->next->next == nullptr) {
            return head->val + head->next->val;
        }

        // Step 1: Count total number of nodes
        int length = 0;
        ListNode* current = head;
        while (current != nullptr) {
            length++;
            current = current->next;
        }

        int half = length / 2;

        // Step 2: Store first half values in a map
        unordered_map<int, int> twinSums;
        current = head;
        int index = 0;
        while (index < half) {
            twinSums[index] = current->val;
            current = current->next;
            index++;
        }

        // Step 3: Add second half values in reverse order to map
        index = half - 1;
        while (current != nullptr && index >= 0) {
            twinSums[index] += current->val;
            current = current->next;
            index--;
        }

        // Step 4: Find maximum twin sum
        int maxTwinSum = INT_MIN;
        for (auto& pair : twinSums) {
            maxTwinSum = max(maxTwinSum, pair.second);
        }

        return maxTwinSum;
    }
};
