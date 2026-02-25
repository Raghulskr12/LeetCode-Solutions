/**
 * Definition for a binary tree node.
 */
class Solution {

    public boolean isLeaf(TreeNode root) {
        return root != null &&
               root.left == null &&
               root.right == null;
    }

    public void dfs(TreeNode root, List<String> ans, String path) {

        if (root == null) return;

        // Build path
        path += root.val;

        // If leaf → store
        if (isLeaf(root)) {
            ans.add(path);
            return;
        }

        // Add arrow only if not leaf
        path += "->";

        dfs(root.left, ans, path);
        dfs(root.right, ans, path);
    }

    public List<String> binaryTreePaths(TreeNode root) {

        List<String> ans = new ArrayList<>();
        dfs(root, ans, "");
        return ans;
    }
}