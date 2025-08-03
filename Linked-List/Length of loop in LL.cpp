/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        unordered_map<ListNode*, int> visitedIndex;
        ListNode* current = head;
        int index = 0;

        // Traverse and record index of each visited node
        while (current) {
            if (visitedIndex.find(current) != visitedIndex.end()) {
                // Loop detected
                break;
            }
            visitedIndex[current] = index;
            index++;
            current = current->next;
        }

        // If no loop was found
        if (current == nullptr) return 0;

        // Length of loop = current index - first occurrence index of loop node
        return index - visitedIndex[current];
    }
};
