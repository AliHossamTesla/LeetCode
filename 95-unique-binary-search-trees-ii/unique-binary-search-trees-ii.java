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
    public List<TreeNode> generateTrees(int n) {
        // List<TreeNode> ans = new ArrayList<>();
        return calc(1, n);
    }
    private List<TreeNode> calc(int st, int ed){
        if (st > ed) {
            List<TreeNode> ans = new ArrayList<>();
            ans.add(null);
            return ans;
        }
        if(st == ed){
            List<TreeNode> ans = new ArrayList<>();
            ans.add(new TreeNode(st));
            return ans;
        }
        List<TreeNode> ans = new ArrayList<>();
        for(int i = st ; i <= ed ; i ++){
            List<TreeNode>lft = calc(st, i - 1);
            List<TreeNode>rgt =  calc(i + 1, ed);
            for(TreeNode l : lft){
                for(TreeNode r : rgt){
                    ans.add(new TreeNode(i, l, r));
                }
            }
        }
        return ans ;
    }
}