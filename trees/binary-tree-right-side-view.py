
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        res = []
        self.helper(root, res, 0)
        return res
        
    def helper(self, curr:TreeNode, res: List[int], curr_depth: int) -> None:
        if curr is None:
            return
        if curr_depth == len(res):
            res.append(curr.val)
        self.helper(curr.right, res, curr_depth+1)
        self.helper(curr.left, res, curr_depth+1)
        
