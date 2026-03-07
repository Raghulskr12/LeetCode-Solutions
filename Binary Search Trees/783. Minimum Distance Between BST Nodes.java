/**
 * Definition for a binary tree node.
 * Each node contains:
 *  - value (val)
 *  - reference to left child
 *  - reference to right child
 */
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}

    TreeNode(int val) { 
        this.val = val; 
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {

    /**
     * DFS function to perform inorder traversal.
     * 
     * temp[0] -> stores value of previously visited node
     * ans[0]  -> stores minimum difference found so far
     */
    public void dfs(TreeNode root, int[] temp, int[] ans) {

        // Base case: if node is null, return
        if (root == null) {
            return;
        }

        // 1️⃣ Traverse left subtree
        dfs(root.left, temp, ans);

        // 2️⃣ Process current node
        // Calculate difference between current node and previous node
        ans[0] = Math.min(ans[0], Math.abs(temp[0] - root.val));

        // Update previous node value
        temp[0] = root.val;

        // 3️⃣ Traverse right subtree
        dfs(root.right, temp, ans);
    }

    /**
     * Main function to compute minimum difference
     */
    public int getMinimumDifference(TreeNode root) {

        // ans[0] stores the minimum difference
        int[] ans = new int[1];

        // temp[0] stores the previous node value during traversal
        int[] temp = new int[1];

        // Initialize ans with maximum possible value
        ans[0] = Integer.MAX_VALUE;

        // Initialize previous node with max value
        temp[0] = Integer.MAX_VALUE;

        // Start DFS inorder traversal
        dfs(root, temp, ans);

        // Return the minimum difference found
        return ans[0];
    }
}