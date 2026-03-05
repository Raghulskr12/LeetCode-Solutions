class Solution {

    public TreeNode movetoright(TreeNode root)
    {
        while(root.right != null)
        {
            root = root.right;
        }
        return root;
    }

    public TreeNode Helper(TreeNode root)
    {
        if(root.right == null)
        {
            return root.left;
        }

        if(root.left == null)
        {
            return root.right;
        }

        TreeNode rightend = movetoright(root.left);
        rightend.right = root.right;

        return root.left;
    }

    public TreeNode deleteNode(TreeNode root, int key)
    {
        if(root == null) return null;

        if(root.val == key)
        {
            return Helper(root);
        }

        TreeNode temp = root;

        while(root != null)
        {
            if(key < root.val)
            {
                if(root.left != null && root.left.val == key)
                {
                    root.left = Helper(root.left);
                    break;
                }
                root = root.left;
            }
            else
            {
                if(root.right != null && root.right.val == key)
                {
                    root.right = Helper(root.right);
                    break;
                }
                root = root.right;
            }
        }

        return temp;
    }
}