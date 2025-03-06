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
        // Serialize both trees
        String rootStr = serialize(a);
        String subRootStr = serialize(b);
        char[] aa = (subRootStr + '#' + rootStr).toCharArray();
        int n = aa.length ;
        int[] pi = new int[n];
        for(int i = 1 ; i < n ; i ++){
            int j = pi[i - 1];
            while(j > 0 && aa[i] != aa[j]) j = pi[j - 1];
            if(aa[i] == aa[j]) j ++ ;
            if(j == subRootStr.length()) return true ;
            pi[i] = j ;
        }
        return false ;
    }
    private String serialize(TreeNode node) {
        // Use StringBuilder for efficient string concatenation
        StringBuilder sb = new StringBuilder();
        serializeHelper(node, sb);
        return sb.toString();
    }

    private void serializeHelper(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append("#"); // Use '#' to represent null nodes
            return;
        }
        // Pre-order traversal: root, left, right
        sb.append(",").append(node.val).append(","); // Add delimiters
        serializeHelper(node.left, sb);
        serializeHelper(node.right, sb);
    }
}