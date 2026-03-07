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

    TreeNode(int value) {
        this.val = value;
    }

    TreeNode(int value, TreeNode leftChild, TreeNode rightChild) {
        this.val = value;
        this.left = leftChild;
        this.right = rightChild;
    }
}

class Solution {

    /**
     * This function checks whether the value of the root node
     * is equal to the sum of its left and right child nodes.
     *
     * @param root The root node of the binary tree
     * @return true if root value == left child value + right child value
     *         false otherwise
     */
    public boolean checkTree(TreeNode root) {

        // Store left child value
        int leftChildValue = root.left.val;

        // Store right child value
        int rightChildValue = root.right.val;

        // Store root node value
        int rootValue = root.val;

        // Check if root value equals the sum of its children
        if (leftChildValue + rightChildValue == rootValue) {
            return true;
        }

        // Otherwise return false
        return false;
    }
}