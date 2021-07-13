
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# 83.4% faster solution from online leetcode community.
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        maxes = []
        if root is None:
            return maxes
        q = deque([root])
        
        while len(q) > 0:
            num_nodes = len(q)
            maxi = -float("inf")
            for i in range(num_nodes):
                curr_tn = q.popleft()
                maxi = max(maxi, curr_tn.val)
                if curr_tn.left is not None:
                    q.append(curr_tn.left)
                if curr_tn.right is not None:
                    q.append(curr_tn.right)
            maxes.append(maxi)
        
        return maxes
        

# my 8% faster solution.
class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        res = [(0, root)] #[lvl, TreeNode]
        db = {i: [] for i in range(10**4 + 1)} #{level: [val-1, ..., val-n]}
        db[0] = [root.val]
        while len(res) > 0:
            curr = res.pop(0)
            lvl, curr_tn = curr[0], curr[1]
            if curr_tn.left is not None:
                db[lvl+1].append(curr_tn.left.val)
                res.append((lvl+1, curr_tn.left))
                
            if curr_tn.right is not None:
                db[lvl+1].append(curr_tn.right.val)
                res.append((lvl+1, curr_tn.right))
        maxis = []
        for k in db:
            if len(db[k]) != 0:
                maxis.append(max(db[k]))
        return maxis
        
