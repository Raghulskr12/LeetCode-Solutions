class Solution {
    
    public boolean isLeaf(TreeNode root) {
        return root.left == null && root.right == null;
    }
    
    public void dfs(TreeNode root, int temp, int[] ans) {
        if (root == null) return;

        // Correct formula
        temp = temp * 10 + root.val;

        if (isLeaf(root)) {
            ans[0] += temp;
            return;   // Important to stop further calls
        }

        dfs(root.left, temp, ans);
        dfs(root.right, temp, ans);
    }
    
    public int sumNumbers(TreeNode root) {
        if (root == null) return 0;

        int[] ans = new int[1];
        dfs(root, 0, ans);
        return ans[0];
    }
}