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

    public void dfs(TreeNode root, List<Integer> ans, int level) {

        // Base case
        if (root == null) return;

        // First node at this level → visible from right
        if (level == ans.size()) {
            ans.add(root.val);
        }

        // Visit right first
        dfs(root.right, ans, level + 1);
        dfs(root.left, ans, level + 1);
    }

    public List<Integer> rightSideView(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        dfs(root, ans, 0);
        return ans;
    }
}