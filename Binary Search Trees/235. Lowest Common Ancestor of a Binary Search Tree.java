/**
 * Definition for a binary tree node.
 * Each node contains:
 * - value (val)
 * - left child
 * - right child
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    // Constructor to create node with value
    TreeNode(int x) { 
        val = x; 
    }
}

class Solution {

    /**
     * Helper function to find the Lowest Common Ancestor (LCA)
     * in a Binary Search Tree.
     * 
     * root -> current node
     * p -> first node
     * q -> second node
     */
    public TreeNode lca(TreeNode root, TreeNode p, TreeNode q) {

        // Base case: if tree is empty
        if (root == null) {
            return null;
        }

        // Store current node value
        int curr = root.val;

        /*
        If both nodes are smaller than current node,
        then LCA must lie in the left subtree
        */
        if (curr > p.val && curr > q.val) {
            return lca(root.left, p, q);
        }

        /*
        If both nodes are greater than current node,
        then LCA must lie in the right subtree
        */
        if (curr < p.val && curr < q.val) {
            return lca(root.right, p, q);
        }

        /*
        If one node is on the left and the other is on the right,
        or one node equals the current node,
        then current node is the Lowest Common Ancestor
        */
        return root;
    }

    /**
     * Main function called by the problem
     */
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        return lca(root, p, q);
    }
}