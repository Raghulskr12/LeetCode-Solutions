class Solution {
    int min;

    public int findSecondMinimumValue(TreeNode root) {
        min = root.val;
        long ans = dfs(root);
        return ans < Long.MAX_VALUE ? (int) ans : -1;
    }

    private long dfs(TreeNode node) {
        if (node == null) return Long.MAX_VALUE;

        if (node.val > min) return node.val;

        long left = dfs(node.left);
        long right = dfs(node.right);

        return Math.min(left, right);
    }
}