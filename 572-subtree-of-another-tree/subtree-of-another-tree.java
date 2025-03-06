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

        // Check if subRootStr is a substring of rootStr
        return rootStr.contains(subRootStr);
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