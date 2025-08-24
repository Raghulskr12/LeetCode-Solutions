/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    
    // Function to merge two sorted linked lists into one sorted list
    public ListNode merge(ListNode leftHead, ListNode rightHead) {
        // Dummy node to act as the starting point
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy; // Pointer to build the merged list
        
        // Merge nodes from both lists in sorted order
        while (leftHead != null && rightHead != null) {
            if (leftHead.val < rightHead.val) {
                tail.next = leftHead;
                leftHead = leftHead.next;
            } else {
                tail.next = rightHead;
                rightHead = rightHead.next;
            }
            tail = tail.next; // Move tail forward
        }
        
        // Attach the remaining nodes (if any)
        if (leftHead != null) {
            tail.next = leftHead;
        } else {
            tail.next = rightHead;
        }
        
        return dummy.next; // The sorted list starts after dummy
    }
    
    // Function to find the middle node of a linked list
    public ListNode getMiddle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head.next; // Fast starts one step ahead
        
        // Move slow by 1 and fast by 2 until fast reaches the end
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        return slow; // Slow will be at the middle
    }
    
    // Function to sort the linked list using Merge Sort
    public ListNode sortList(ListNode head) {
        // Base case: 0 or 1 element is already sorted
        if (head == null || head.next == null) {
            return head;
        }
        
        // Step 1: Split the list into two halves
        ListNode middle = getMiddle(head);
        ListNode rightHalf = middle.next;
        middle.next = null; // Break the link
        ListNode leftHalf = head;
        
        // Step 2: Recursively sort both halves
        leftHalf = sortList(leftHalf);
        rightHalf = sortList(rightHalf);
        
        // Step 3: Merge the two sorted halves
        return merge(leftHalf, rightHalf);
    }
}
