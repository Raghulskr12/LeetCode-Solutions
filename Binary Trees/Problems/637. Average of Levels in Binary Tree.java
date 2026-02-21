class Solution {

    public List<Double> averageOfLevels(TreeNode root) {

        List<Double> ans = new ArrayList<>();

        // 🔹 Edge case
        if(root == null) return ans;

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while(!q.isEmpty())
        {
            int size = q.size();

            double sum = 0;

            for(int i = 0; i < size; i++)
            {
                TreeNode node = q.poll();

                sum += node.val;

                if(node.left != null)
                {
                    q.offer(node.left);
                }

                if(node.right != null)
                {
                    q.offer(node.right);
                }
            }

            // Calculate average for this level
            ans.add(sum / size);
        }

        return ans;
    }
}