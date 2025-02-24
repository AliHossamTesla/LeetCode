# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, a: List[int], b: List[int]) -> Optional[TreeNode]:
        n = len(a)
        idx = {val: i for i, val in enumerate(b)}  # Map values to postorder indices
        preIdx = 0  # Track current root index in preorder
        
        def cons(s, e):
            nonlocal preIdx
            if s > e:
                return None
            
            root = TreeNode(a[preIdx])
            preIdx += 1
            if s == e:
                return root  # Leaf node

            # Left subtree root is a[preIdx]
            leftSubtreeIdx = idx[a[preIdx]]  # Get its position in postorder
            
            # Recursively construct left and right subtrees
            root.left = cons(s, leftSubtreeIdx)
            root.right = cons(leftSubtreeIdx + 1, e - 1)  # Exclude root itself

            return root
        
        return cons(0, n - 1)
