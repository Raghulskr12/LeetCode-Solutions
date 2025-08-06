class Solution {
public:
    ListNode* rev(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        prev->next = nullptr;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head->next == NULL || left == right) return head;

        ListNode* prev = nullptr;
        ListNode* end = nullptr;
        ListNode* temp = head;
        int count = 1;
        ListNode* pass = nullptr;

        while (temp != nullptr) {
            if (left == 1 && count == 1) {
                pass = temp;
            }
            if (count == left - 1) {
                prev = temp;
                pass = temp->next;
            }
            if (count == right) {
                end = temp->next;
                temp->next = nullptr;
                break;
            }
            count++;
            temp = temp->next;
        }

        ListNode* reversed = rev(pass);
        if (left == 1) {
            head = reversed;
        } else {
            prev->next = reversed;
        }

        // Traverse to the end of the reversed part to reconnect
        temp = reversed;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = end;

        return head;
    }
};
