
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, t_sum: int) -> List[List[int]]:
        res = []
        if not root:
            return res
        stack = [(root, t_sum-root.val, [root.val])]
        while stack:
            c_root, c_sum, ls = stack.pop()
            if not c_root.left and not c_root.right and c_sum == 0:
                res.append(ls)
            
            if c_root.right is not None:
                t = (c_root.right, c_sum-c_root.right.val, ls + [c_root.right.val])
                stack.append(t)
            if c_root.left is not None:
                t = (c_root.left, c_sum-c_root.left.val, ls + [c_root.left.val])
                stack.append(t)
        return res
