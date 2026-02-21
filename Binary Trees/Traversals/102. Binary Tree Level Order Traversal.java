class Solution {

    public List<List<Integer>> levelOrder(TreeNode root) {

        List<List<Integer>> ans = new ArrayList<>();

        // 🔹 Edge case
        if(root == null) return ans;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty())
        {
            int size = q.size();

            // 🔹 Create new list for each level
            List<Integer> level = new ArrayList<>();

            for(int i = 0; i < size; i++)
            {
                TreeNode node = q.poll();

                level.add(node.val);

                // Add left child
                if(node.left != null)
                {
                    q.offer(node.left);
                }

                // Add right child
                if(node.right != null)
                {
                    q.offer(node.right);
                }
            }

            // Add this level to result
            ans.add(level);
        }

        return ans;
    }
}