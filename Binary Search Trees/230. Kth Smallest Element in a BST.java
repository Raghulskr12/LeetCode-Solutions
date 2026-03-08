/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;          // Value of the node
 *     TreeNode left;    // Reference to left child
 *     TreeNode right;   // Reference to right child
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

    // DFS function to perform inorder traversal
    public void dfs(TreeNode root, int k, int[] count, int[] ans)
    {
        // Base case: if node is null return
        if(root == null)
        {
            return;
        }

        // Traverse left subtree
        dfs(root.left, k, count, ans);

        // Increment the count when visiting a node
        count[0]++;

        // If the current visited node is the kth node
        if(count[0] == k)
        {
            ans[0] = root.val;   // Store the kth smallest value
        }

        // Traverse right subtree
        dfs(root.right, k, count, ans);
    }

    public int kthSmallest(TreeNode root, int k) {

        // Array used to store the answer (size 1 to simulate pass by reference)
        int[] ans = new int[1];

        // Counter to keep track of how many nodes have been visited
        int[] count = new int[1];

        ans[0] = 0;
        count[0] = 0;

        // Start DFS traversal
        dfs(root, k, count, ans);

        // Return the kth smallest element
        return ans[0];
    }
}