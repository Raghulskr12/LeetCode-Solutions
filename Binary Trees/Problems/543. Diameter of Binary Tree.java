class Solution {

    /*
     * dfs() returns the HEIGHT of the current subtree.
     * At the same time, it updates the maximum diameter found so far.
     *
     * max[0] stores the global maximum diameter.
     */
    public int dfs(TreeNode root, int[] max) {

        // Base case: height of empty tree is 0
        if (root == null) {
            return 0;
        }

        // Recursively get height of left subtree
        int leftHeight = dfs(root.left, max);

        // Recursively get height of right subtree
        int rightHeight = dfs(root.right, max);

        // Diameter passing through current node
        // = left subtree height + right subtree height
        max[0] = Math.max(max[0], leftHeight + rightHeight);

        // Return height of current subtree
        return 1 + Math.max(leftHeight, rightHeight);
    }

    public int diameterOfBinaryTree(TreeNode root) {

        // Array used to store global maximum diameter
        int[] max = new int[1];

        // No need for Integer.MIN_VALUE
        // Because diameter is always >= 0
        max[0] = 0;

        dfs(root, max);

        return max[0];
    }
}