class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        
        if (root == null) return null;

        // If current node is p or q → return it
        if (root == p || root == q) return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        // Case 1: Found in both sides
        if (left != null && right != null) {
            return root;
        }

        // Case 2: Found in one side
        return left != null ? left : right;
    }
}