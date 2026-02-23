class Solution {

    /*
     * Returns:
     * - Height of subtree if balanced
     * - -1 if subtree is NOT balanced
     */
    public int dfs(TreeNode root) {

        // Base case: empty tree has height 0
        if (root == null) {
            return 0;
        }

        // Get height of left subtree
        int leftHeight = dfs(root.left);

        // If left subtree is already unbalanced → stop early
        if (leftHeight == -1) {
            return -1;
        }

        // Get height of right subtree
        int rightHeight = dfs(root.right);

        // If right subtree is already unbalanced → stop early
        if (rightHeight == -1) {
            return -1;
        }

        // Check current node balance condition
        if (Math.abs(leftHeight - rightHeight) > 1) {
            return -1;  // Not balanced
        }

        // Return height if balanced
        return 1 + Math.max(leftHeight, rightHeight);
    }

    public boolean isBalanced(TreeNode root) {

        // If dfs returns -1 → tree is not balanced
        return dfs(root) != -1;
    }
}