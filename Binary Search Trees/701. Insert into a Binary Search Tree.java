class Solution {

    public void dfs(TreeNode root,int value)
    {
        if(value < root.val)
        {
            if(root.left == null){
                root.left = new TreeNode(value);
                return;
            }
            dfs(root.left,value);
        }
        else
        {
            if(root.right == null){
                root.right = new TreeNode(value);
                return;
            }
            dfs(root.right,value);
        }
    }

    public TreeNode insertIntoBST(TreeNode root, int val) {

        if(root == null){
            return new TreeNode(val);
        }

        dfs(root,val);
        return root;
    }
}