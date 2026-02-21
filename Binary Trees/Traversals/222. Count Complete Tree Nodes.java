
class Solution {

    public int dfs(TreeNode root)
    {
        if(root == null)
        {
            return 0;
        }

        // Count = 1 (current node)
        // + left subtree nodes
        // + right subtree nodes
        return 1 + dfs(root.left) + dfs(root.right);
    }

    public int countNodes(TreeNode root) {
        return dfs(root);
    }
}