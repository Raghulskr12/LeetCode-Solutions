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

        if (root == null) return;

        // First node visited at this level → leftmost
        if (level == ans.size()) {
            ans.add(root.val);
        }

        // Visit LEFT first
        dfs(root.left, ans, level + 1);
        dfs(root.right, ans, level + 1);
    }

    public int findBottomLeftValue(TreeNode root) {

        List<Integer> ans = new ArrayList<>();
        dfs(root, ans, 0);

        // Last level's first node
        return ans.get(ans.size() - 1);
    }
}