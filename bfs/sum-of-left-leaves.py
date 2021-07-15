
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        res = []
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 0
            
        q = deque([root])
        while len(q) > 0:
            curr_tn = q.popleft()
            if curr_tn.left is not None:
                q.append(curr_tn.left)
                # leaf check.
                if curr_tn.left.left is None and curr_tn.left.right is None:
                    res.append(curr_tn.left.val)
            if curr_tn.right is not None:
                q.append(curr_tn.right)
                
        return sum(res)
        
