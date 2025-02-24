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
    private int n;
    
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        n = preorder.length;
        return construct(0, n - 1, 0, n - 1, preorder, postorder);
    }

    private TreeNode construct(int l, int r, int lx, int rx, int[] pre, int[] pos) {
        if (l > r || lx > rx) return null;
        if (l == r) return new TreeNode(pre[l]);

        TreeNode head = new TreeNode(pre[l]);
        int rx_ = lx;
        int r_ = l + 1;

        while (pre[l + 1] != pos[rx_]) {
            rx_++;
            r_++;
        }

        head.left = construct(l + 1, r_, lx, rx_, pre, pos);
        if (r_ + 1 <= r) { // Ensure bounds are valid
            head.right = construct(r_ + 1, r, rx_ + 1, rx, pre, pos);
        }

        return head;
    }
}
