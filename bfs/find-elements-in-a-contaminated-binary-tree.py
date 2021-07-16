
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class FindElements:

    def __init__(self, root: TreeNode):
        self.seen = set()
        self.root = root
        if root is not None:
            self.root.val = 0
            self.seen.add(self.root.val)
            
        self.dq = deque([self.root])
        while len(self.dq) > 0:
            curr = self.dq.popleft()
            if curr.left is not None:
                curr.left.val = curr.val*2 + 1
                self.seen.add(curr.left.val)
                self.dq.append(curr.left)
            if curr.right is not None:
                curr.right.val = curr.val*2 + 2
                self.seen.add(curr.right.val)
                self.dq.append(curr.right)

    def find(self, target: int) -> bool:
        return target in self.seen
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
