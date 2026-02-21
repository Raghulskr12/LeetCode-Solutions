class Solution {

    public List<Integer> preorderTraversal(TreeNode root) {

        // 🔹 List to store preorder result
        List<Integer> ans = new ArrayList<>();

        // 🔹 Stack to simulate recursion
        Stack<TreeNode> freq = new Stack<>();

        // Infinite loop — we break manually when traversal ends
        while(true)
        {
            // 🔹 CASE 1: Current node exists
            if(root != null)
            {
                // Step 1: Visit ROOT (Preorder rule)
                ans.add(root.val);

                // Step 2: Push node to stack
                // We will return later to process its right subtree
                freq.add(root);

                // Step 3: Move LEFT
                root = root.left;
            }
            else
            {
                // 🔹 CASE 2: root is null → left subtree finished

                // If stack empty → traversal done
                if(freq.size() == 0) break;

                // Backtrack to last node
                root = freq.pop();

                // Move to RIGHT subtree
                root = root.right;
            }
        }

        return ans;
    }
}