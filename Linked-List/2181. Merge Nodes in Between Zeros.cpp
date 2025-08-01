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
    ListNode* mergeNodes(ListNode* head) {
        // Dummy node to help build the result list
        ListNode* resultHead = new ListNode(-1);
        ListNode* resultTail = resultHead;

        int segmentSum = 0;       // To hold sum between two 0s
        ListNode* current = head->next; // Skip the first 0 node

        while (current != nullptr) {
            if (current->val == 0) {
                // End of a segment, create a node with the sum
                ListNode* newNode = new ListNode(segmentSum);
                resultTail->next = newNode;
                resultTail = resultTail->next;
                segmentSum = 0; // Reset sum for next segment
            } else {
                segmentSum += current->val;
            }
            current = current->next;
        }

        return resultHead->next; // Skip dummy node
    }
};
