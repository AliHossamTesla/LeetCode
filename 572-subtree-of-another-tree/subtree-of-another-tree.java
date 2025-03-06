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
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        List<TreeNode> ans = trav(root, subRoot);
        if(ans.size() == 0) return false ;
        for(TreeNode t : ans){
            if(dfs(t, subRoot)) return true ;
        }
        return false ;
    }
    private boolean dfs(TreeNode a, TreeNode b){
        if(a == null && b == null) return true ;
        if(a == null || b == null || a.val != b.val) return false;
        if(!dfs(a.left, b.left)) return false ;
        if(!dfs(a.right, b.right)) return false ;
        return true ;
    }
    private List<TreeNode> trav(TreeNode root, TreeNode h){
        ArrayDeque<TreeNode> t = new ArrayDeque<>();
        t.add(root);
        List<TreeNode> ans = new ArrayList<>();
        while(!t.isEmpty()){
            TreeNode cr = t.poll();
            if(cr.val == h.val){
                ans.add(cr);
            }
            if(cr.left != null) t.add(cr.left);
            if(cr.right != null) t.add(cr.right);
        }
        return ans ;
    }
}