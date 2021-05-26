# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        res = []
        stack = [(root, "")]
        
        while len(stack) != 0:
            c_root, c_str = stack.pop()
            if c_root.left is None and c_root.right is None:
                c_str += str(c_root.val)
                res.append(c_str)
            if c_root.left is not None:
                new_elem = (c_root.left, c_str + str(c_root.val) + "->")
                stack.append(new_elem)
            if c_root.right is not None:
                new_elem = (c_root.right, c_str + str(c_root.val) + "->")
                stack.append(new_elem)
        
        return res
