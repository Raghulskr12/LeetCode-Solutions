class Solution {

    public boolean isMirror(TreeNode t1, TreeNode t2) {

        // Case 1: Both null → symmetric
        if (t1 == null && t2 == null) {
            return true;
        }

        // Case 2: One null → not symmetric
        if (t1 == null || t2 == null) {
            return false;
        }

        // Case 3: Values differ
        if (t1.val != t2.val) {
            return false;
        }

        // Case 4: Mirror check
        return isMirror(t1.left, t2.right) &&
               isMirror(t1.right, t2.left);
    }

    public boolean isSymmetric(TreeNode root) {

        if (root == null) {
            return true;
        }

        return isMirror(root.left, root.right);
    }
}