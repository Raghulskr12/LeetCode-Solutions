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

    public boolean isLeaf(TreeNode root) {
        return root.left == null && root.right == null;
    }

    public void dfs(TreeNode root, List<Integer> ans) {

        if (root == null) return;

        if (isLeaf(root)) {
            ans.add(root.val);
        }

        dfs(root.left, ans);
        dfs(root.right, ans);
    }

    public boolean leafSimilar(TreeNode root1, TreeNode root2) {

        List<Integer> temp1 = new ArrayList<>();
        List<Integer> temp2 = new ArrayList<>();

        dfs(root1, temp1);
        dfs(root2, temp2);

        if (temp1.size() != temp2.size()) return false;

        for (int i = 0; i < temp1.size(); i++) {
            if (!temp1.get(i).equals(temp2.get(i))) {
                return false;
            }
        }

        return true;
    }
}