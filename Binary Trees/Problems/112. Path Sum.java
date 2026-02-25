/**
 * Definition for a binary tree node.
 */
class Solution {

    public boolean isLeaf(TreeNode root) {
        return root.left == null && root.right == null;
    }

    public boolean dfs(TreeNode root, int sum, int target) {

        if (root == null) return false;

        // Add current node value
        sum += root.val;

        // If leaf → check sum
        if (isLeaf(root)) {
            return sum == target;
        }

        // Explore left OR right
        return dfs(root.left, sum, target) ||
               dfs(root.right, sum, target);
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
}