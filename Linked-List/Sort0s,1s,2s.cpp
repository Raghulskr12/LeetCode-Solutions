/*
Definition of singly linked list:
struct ListNode {
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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        // Dummy heads for 0s, 1s, 2s
        ListNode* zeroDummy = new ListNode(-1);
        ListNode* oneDummy = new ListNode(-1);
        ListNode* twoDummy = new ListNode(-1);

        ListNode* zero = zeroDummy;
        ListNode* one = oneDummy;
        ListNode* two = twoDummy;

        ListNode* curr = head;

        // Distribute nodes
        while (curr != nullptr) {
            if (curr->val == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->val == 1) {
                one->next = curr;
                one = one->next;
            } else {
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Properly end the last list to avoid cycle
        two->next = nullptr;

        // Connect all three lists
        one->next = twoDummy->next;
        zero->next = oneDummy->next;

        // Final head
        return zeroDummy->next;
    }
};
