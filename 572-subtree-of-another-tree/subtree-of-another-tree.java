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
    public boolean isSubtree(TreeNode a, TreeNode b) {
        if(a == null || b == null) return false ;
        if(isSameTree(a, b)) return true ;
        return isSubtree(a.left, b) || isSubtree(a.right, b);
    }
    public boolean isSameTree(TreeNode a, TreeNode b){
        if(a == null && b == null) return true ;
        if(a == null || b == null || a.val != b.val) return false;
        return isSameTree(a.left, b.left) && isSameTree(a.right, b.right);
    }
}