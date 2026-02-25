/**
 * Definition for a binary tree node.
 */
class Solution {

    public void dfs(TreeNode root,
                    List<List<Integer>> ans,
                    List<Integer> path,
                    int sum,
                    int target) {

        if (root == null) return;

        // Add node
        sum += root.val;
        path.add(root.val);

        // If leaf → check sum
        if (root.left == null && root.right == null) {

            if (sum == target) {
                ans.add(new ArrayList<>(path));
            }

        } else {

            dfs(root.left, ans, path, sum, target);
            dfs(root.right, ans, path, sum, target);
        }

        // Backtrack
        path.remove(path.size() - 1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {

        List<List<Integer>> ans = new ArrayList<>();
        dfs(root, ans, new ArrayList<>(), 0, targetSum);
        return ans;
    }
}