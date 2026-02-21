class Solution {

    /**
     * DFS function for Postorder Traversal
     * Order: Left → Right → Root
     */
    public void dfs(List<Integer> ans, TreeNode root)
    {
        // 🔹 Base case:
        // If node is null, nothing to process
        if(root == null) return;

        // 🔹 Step 1: Traverse LEFT subtree
        dfs(ans, root.left);

        // 🔹 Step 2: Traverse RIGHT subtree
        dfs(ans, root.right);

        // 🔹 Step 3: Visit ROOT node
        ans.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {

        // List to store result
        List<Integer> ans = new ArrayList<>();

        // Start DFS
        dfs(ans, root);

        return ans;
    }
}