/**
 * Definition for a binary tree node.
 * Each node contains:
 * - an integer value
 * - reference to left child
 * - reference to right child
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    // Constructor to create a node with value
    TreeNode(int val) { 
        this.val = val; 
    }

    // Constructor to create a node with value and children
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    /**
     * Recursive helper function to validate BST
     * 
     * root -> current node being checked
     * min  -> minimum allowed value for the node
     * max  -> maximum allowed value for the node
     */
    public boolean isValid(TreeNode root, long min, long max) {

        // Base Case:
        // If node is null, it is valid
        if (root == null) {
            return true;
        }

        // If current node value violates BST rules
        // it must lie strictly between min and max
        if (root.val <= min || root.val >= max) {
            return false;
        }

        // Recursively validate the left subtree
        // Left subtree values must be < current node value
        boolean left = isValid(root.left, min, root.val);

        // Recursively validate the right subtree
        // Right subtree values must be > current node value
        boolean right = isValid(root.right, root.val, max);

        // Tree is valid only if both left and right subtrees are valid
        return left && right;
    }

    /**
     * Main function called by the problem
     * Starts recursion with full possible range of values
     */
    public boolean isValidBST(TreeNode root) {

        // Use Long.MIN_VALUE and Long.MAX_VALUE
        // to avoid integer overflow problems
        return isValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}