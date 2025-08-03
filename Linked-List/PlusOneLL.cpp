/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() {
        val = 0;
        next = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1) {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    // Recursive helper to handle carry while moving from tail to head
    int addWithCarry(ListNode* node) {
        if (node == nullptr) {
            return 1; // Start by adding 1 at the end (least significant digit)
        }

        int carry = addWithCarry(node->next);
        node->val += carry;

        if (node->val >= 10) {
            node->val = 0;
            return 1; // Carry over
        }

        return 0; // No carry needed
    }

    ListNode* addOne(ListNode* head) {
        int carry = addWithCarry(head);

        // If carry remains after full traversal, add new node at head
        if (carry) {
            ListNode* newHead = new ListNode(1, head);
            return newHead;
        }

        return head;
    }
};
