
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: TreeNode) -> int:
        dp = {} # {TreeNode: robbed_sum}
        return self.robSub(root, dp)
        
    def robSub(self, root: TreeNode, memory: Dict[TreeNode, int]=None) -> int:
        if root is None:
            return 0
        if root in memory:
            return memory[root]
        val = root.val
        if root.left is not None:
            val += self.robSub(root.left.left, memory) + \
                   self.robSub(root.left.right, memory)
        if root.right is not None:
            val += self.robSub(root.right.left, memory) + \
                   self.robSub(root.right.right, memory)
        
        direct_robsum = self.robSub(root.left, memory) + self.robSub(root.right, memory)
        memory[root] = max(val, direct_robsum)
        return memory[root]
