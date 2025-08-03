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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ✅ Optimized Two-Pointer Approach (O(n) time, O(1) space)
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists; when either reaches end, redirect to other head
        while (ptrA != ptrB) {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }

        return ptrA; // Will be nullptr if no intersection, or the intersection node

        /*
        🔁 Alternate Approach Using Set (O(n) time, O(n) space)

        set<ListNode*> visited;
        ListNode* temp = headA;

        // Store all nodes of list A
        while (temp != nullptr) {
            visited.insert(temp);
            temp = temp->next;
        }

        // Traverse list B and find first node already visited
        temp = headB;
        while (temp != nullptr) {
            if (visited.find(temp) != visited.end()) {
                return temp; // Intersection found
            }
            temp = temp->next;
        }

        return nullptr; // No intersection
        */
    }
};
