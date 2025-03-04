/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = Integer.MIN_VALUE ;
    public int maxPathSum(TreeNode root) {
        calc(root);
        return ans ;
    }
    private int calc(TreeNode root){
        if(root == null) return 0 ;
        int l = Math.max(0, calc(root.left));
        int r = Math.max(0, calc(root.right));
        int v = root.val ;
        ans = Math.max(ans, l + r + v);
        return v + Math.max(l, r);
    }
}