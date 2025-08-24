/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

import java.util.HashMap;

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return null;

        // Map to store mapping: Original Node -> Cloned Node
        HashMap<Node, Node> map = new HashMap<>();

        // Step 1: Create a copy of each node and store in map
        Node current = head;
        while (current != null) {
            Node cloneNode = new Node(current.val);
            map.put(current, cloneNode);
            current = current.next;
        }

        // Step 2: Assign next and random pointers for cloned nodes
        current = head;
        while (current != null) {
            Node cloneNode = map.get(current);
            cloneNode.next = map.get(current.next);     // set next pointer
            cloneNode.random = map.get(current.random); // set random pointer
            current = current.next;
        }

        // Return head of the cloned list
        return map.get(head);
    }
}
