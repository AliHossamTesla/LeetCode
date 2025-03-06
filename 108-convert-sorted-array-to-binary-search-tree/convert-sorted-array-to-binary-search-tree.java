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
    public TreeNode sortedArrayToBST(int[] nums) {
        return construct(nums, 0, nums.length - 1);
    }
    private TreeNode construct(int[] a, int l, int r){
        if(l > r) return null ;
        int md = (r + l)/2 ;
        TreeNode root = new TreeNode(a[md]);
        root.left = construct(a, l, md - 1);
        root.right = construct(a, md + 1, r);
        return root ;
    }  
}