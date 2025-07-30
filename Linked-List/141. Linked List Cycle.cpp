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
    bool hasCycle(ListNode *head) {
        // Map to store the frequency of visited nodes
        unordered_map<ListNode*, int> visitedNodes;
        
        // Start from the head of the list
        ListNode* current = head;
        
        // Traverse the list
        while (current != nullptr) {
            // If current node is already visited, cycle exists
            if (visitedNodes[current] > 0) {
                return true;
            }

            // Mark the current node as visited
            visitedNodes[current]++;
            
            // Move to the next node
            current = current->next;
        }
        
        // No cycle found
        return false;
    }
};
