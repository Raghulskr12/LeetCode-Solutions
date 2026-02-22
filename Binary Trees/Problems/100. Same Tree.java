class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {

        // Case 1: Both null
        if (p == null && q == null) {
            return true;
        }

        // Case 2: One is null
        if (p == null || q == null) {
            return false;
        }

        // Case 3: Values different
        if (p.val != q.val) {
            return false;
        }

        // Case 4: Check left AND right subtree
        return isSameTree(p.left, q.left) &&
               isSameTree(p.right, q.right);
    }
}