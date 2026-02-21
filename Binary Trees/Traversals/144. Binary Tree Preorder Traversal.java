class Solution {

    /**
     * DFS function for Preorder Traversal
     * Order: Root → Left → Right
     */
    public void dfs(List<Integer> ans, TreeNode root)
    {
        // 🔹 Base Case:
        // If node is null, nothing to process
        if(root == null)
        {
            return;
        }

        // 🔹 Step 1: Visit ROOT first
        ans.add(root.val);

        // 🔹 Step 2: Traverse LEFT subtree
        dfs(ans, root.left);

        // 🔹 Step 3: Traverse RIGHT subtree
        dfs(ans, root.right);
    }


    /**
     * Main function that returns preorder traversal
     */
    public List<Integer> preorderTraversal(TreeNode root) {

        // Create list to store result
        List<Integer> ans = new ArrayList<>();

        // Start DFS
        dfs(ans, root);

        return ans;
    }
}