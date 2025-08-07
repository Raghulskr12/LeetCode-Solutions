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
    // Function to reverse a linked list starting from 'node'
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = nullptr;
        ListNode* nextNode = node->next;
        while (node != nullptr) {
            nextNode = node->next;
            node->next = previous;
            previous = node;
            node = nextNode;
        }
        return previous;
    }

    // Function to get the k-th node from the current node
    ListNode* getKthNode(ListNode* node, int k) {
        k -= 1; // we already consider the current node
        while (node != nullptr && k > 0) {
            k--;
            node = node->next;
        }
        return node;
    }

    // Main function to reverse nodes in k-group
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevGroupTail = nullptr;    // End of previous reversed group
        ListNode* nextGroupHead = nullptr;    // Start of next group to be processed
        ListNode* kthNode = nullptr;          // Kth node in the current group
        ListNode* curr = head;                // Current node being processed

        while (curr != nullptr) {
            // Find the k-th node from the current node
            kthNode = getKthNode(curr, k);

            // If fewer than k nodes left, don't reverse and connect last part
            if (kthNode == nullptr) {
                if (prevGroupTail) {
                    prevGroupTail->next = curr;
                }
                break;
            }

            // Save the node next to k-th node (start of next group)
            nextGroupHead = kthNode->next;
            kthNode->next = nullptr;  // Break current group

            // Reverse the current group
            reverseList(curr);

            // Connect previous group to the new head of reversed group
            if (curr == head) {
                head = kthNode; // New head after first group is reversed
            } else {
                prevGroupTail->next = kthNode;
            }

            // Set up for the next group
            prevGroupTail = curr;
            curr = nextGroupHead;
        }

        return head;
    }
};
