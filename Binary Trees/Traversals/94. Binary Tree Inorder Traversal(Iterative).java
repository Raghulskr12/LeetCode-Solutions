class Solution {

    public List<Integer> inorderTraversal(TreeNode root) {

        // 🔹 Stack is used to simulate recursion
        Stack<TreeNode> temp = new Stack<>();

        // 🔹 List to store final inorder result
        List<Integer> ans = new ArrayList<>();

        // Infinite loop (we manually break when traversal is complete)
        while(true)
        {
            // 🔹 CASE 1: Current node is NOT null
            if(root != null)
            {
                // Push current node to stack
                // (We will come back to it after finishing its left subtree)
                temp.push(root);

                // Move left to reach extreme left node
                root = root.left;
            }
            else
            {
                // 🔹 CASE 2: Current node is null
                // Means we have reached leftmost node

                // If stack is empty → traversal finished
                if(temp.size() == 0) break;

                // Pop last unprocessed node
                root = temp.pop();

                // Visit node (Inorder step: after left)
                ans.add(root.val);

                // Now move to right subtree
                root = root.right;
            }
        }

        return ans;
    }
}