import java.util.HashMap;
import java.util.Map;

class Solution {
    private Map<Integer, Integer> postIndexMap;
    private int preIndex;

    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        postIndexMap = new HashMap<>();
        for (int i = 0; i < postorder.length; i++) {
            postIndexMap.put(postorder[i], i); // Map value to its index in postorder
        }
        preIndex = 0;
        return construct(preorder, postorder, 0, postorder.length - 1);
    }

    private TreeNode construct(int[] preorder, int[] postorder, int left, int right) {
        if (left > right) return null;

        TreeNode root = new TreeNode(preorder[preIndex++]);
        if (left == right) return root; // Leaf node

        int leftChildIndex = postIndexMap.get(preorder[preIndex]);
        root.left = construct(preorder, postorder, left, leftChildIndex);
        root.right = construct(preorder, postorder, leftChildIndex + 1, right - 1);

        return root;
    }
}