import java.util.*;

class Solution {
    public int maxDepth(TreeNode root) {

        // Base case
        if (root == null) {
            return 0;
        }

        int count = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {

            int n = q.size();   // nodes in current level

            for (int i = 0; i < n; i++) {
                TreeNode temp = q.poll();

                if (temp.left != null) {
                    q.offer(temp.left);
                }

                if (temp.right != null) {
                    q.offer(temp.right);
                }
            }

            count++;   // one level completed
        }

        return count;
    }
}


// class Solution {

//     public int dfs(TreeNode root) {

//         // Base case
//         if (root == null) {
//             return 0;
//         }

//         int leftHeight = dfs(root.left);
//         int rightHeight = dfs(root.right);

//         return 1 + Math.max(leftHeight, rightHeight);
//     }

//     public int maxDepth(TreeNode root) {
//         return dfs(root);
//     }
// }