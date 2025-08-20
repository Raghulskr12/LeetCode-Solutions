/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* child1)
    {
        val = data1;
        next = next1;
        child = child1;  // ✅ fixed (child should not be = next1)
    }
};
*/

class Solution {
public:
    // Merge two sorted linked lists (connected by child pointer)
    ListNode* merge(ListNode* list1, ListNode* list2) {
        // Dummy node to act as the head of the merged list
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;

        // Merge like in "merge step" of merge sort
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->child = new ListNode(list1->val); // create node with list1 value
                tail = tail->child;
                list1 = list1->child; // move down list1's child chain
            } else {
                tail->child = new ListNode(list2->val); // create node with list2 value
                tail = tail->child;
                list2 = list2->child; // move down list2's child chain
            }
        }

        // Attach the remaining part of whichever list is not empty
        if (list1) tail->child = list1;
        else tail->child = list2;

        // The merged list starts at dummyHead->child
        return dummyHead->child;
    }

    // Function to flatten the special linked list
    ListNode* flattenLinkedList(ListNode* &head) {
        // Base case: if head is null OR there is no next list
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Recursively flatten the rest of the list (to the right)
        ListNode* flattenedRight = flattenLinkedList(head->next);

        // Merge current list (head) with the flattened right part
        head = merge(head, flattenedRight);

        return head; // return merged head
    }
};
