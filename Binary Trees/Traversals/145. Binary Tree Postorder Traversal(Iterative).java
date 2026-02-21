class Solution {

    public List<Integer> postorderTraversal(TreeNode root) {

        // 🔹 List to store result
        List<Integer> ans = new ArrayList<>();

        // 🔹 Stack to simulate traversal
        Stack<TreeNode> temp = new Stack<>();

        // If root is not null, push it
        if(root != null)
        {
            temp.push(root);
        }

        // Process until stack is empty
        while(!temp.isEmpty())
        {
            // Pop current node
            TreeNode t = temp.pop();

            // Add node value
            // (This is NOT true postorder yet)
            ans.add(t.val);

            // Push LEFT first
            if(t.left != null)
            {
                temp.push(t.left);
            }

            // Push RIGHT after
            if(t.right != null)
            {
                temp.push(t.right);
            }
        }

        // Reverse the list to get actual postorder
        Collections.reverse(ans);

        return ans;
    }
}