class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Dummy node to start building the result list
        ListNode* resultHead = new ListNode(-1);
        ListNode* resultTail = resultHead;

        int index = 1;
        ListNode* current = head;

        // First pass: Add all odd-indexed nodes
        while (current != nullptr) {
            if (index % 2 != 0) {
                resultTail->next = new ListNode(current->val);
                resultTail = resultTail->next;
            }
            current = current->next;
            index++;
        }

        index = 1;
        current = head;

        // Second pass: Add all even-indexed nodes
        while (current != nullptr) {
            if (index % 2 == 0) {
                resultTail->next = new ListNode(current->val);
                resultTail = resultTail->next;
            }
            current = current->next;
            index++;
        }

        return resultHead->next;
    }
};
