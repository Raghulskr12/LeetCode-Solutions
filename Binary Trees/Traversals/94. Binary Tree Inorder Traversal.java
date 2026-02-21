/**
 * Definition for a binary tree node.
 * This is the structure of each node in the tree.
 */
public class TreeNode {
    int val;          // Value stored in the node
    TreeNode left;   // Pointer to left child
    TreeNode right;  // Pointer to right child

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
     * DFS function to perform Inorder Traversal
     * @param ans  → List to store traversal result
     * @param root → Current node being processed
     */
    public void dfs(List<Integer> ans, TreeNode root)
    {
        // 🔹 Base Case
        // If node is null → nothing to traverse → return
        if(root == null)
        {
            return;
        }

        // 🔹 Step 1: Traverse LEFT subtree
        // Go as left as possible before visiting node
        dfs(ans, root.left);

        // 🔹 Step 2: Visit ROOT node
        // Add current node value to answer list
        ans.add(root.val);

        // 🔹 Step 3: Traverse RIGHT subtree
        dfs(ans, root.right);
    }


    /**
     * Main function called by LeetCode / interviewer
     * Returns inorder traversal of tree
     */
    public List<Integer> inorderTraversal(TreeNode root) {

        // 🔹 Create result list
        List<Integer> ans = new ArrayList<>();

        // 🔹 Start DFS traversal from root
        dfs(ans, root);

        // 🔹 Return final inorder list
        return ans;
    }
}