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
        int l = calc(root.left);
        int r = calc(root.right);
        int v = root.val ;
        ans = max(ans, l + r + v, v + max(l, r), v);
        return max(v + max(l, r), v);
    }
    private int max(int...arg){
        int mx = Integer.MIN_VALUE ;
        for(int i : arg){
            mx = Math.max(i, mx);
        }
        return mx ;
    }
}