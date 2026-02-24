class Solution {

    public boolean dfs(TreeNode node, int val) {
        // Base case
        if (node == null) return true;

        // If value mismatch → not unival
        if (node.val != val) return false;

        // Check left and right subtree
        return dfs(node.left, val) &&
               dfs(node.right, val);
    }

    public boolean isUnivalTree(TreeNode root) {
        if (root == null) return true;

        return dfs(root, root.val);
    }
}