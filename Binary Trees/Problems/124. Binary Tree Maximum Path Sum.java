/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {

    private int maxSum = Integer.MIN_VALUE;

    public int dfs(TreeNode root) {
        // Base case
        if (root == null) return 0;

        // Get max path from left and right (ignore negatives)
        int left = Math.max(0, dfs(root.left));
        int right = Math.max(0, dfs(root.right));

        // Update global maximum (path passing through root)
        maxSum = Math.max(maxSum, left + right + root.val);

        // Return max single path (either left or right)
        return root.val + Math.max(left, right);
    }

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return maxSum;
    }
}