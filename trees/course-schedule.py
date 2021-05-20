class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # make adj_list
        adj_list = {}
        for c in range(numCourses):
            adj_list[c] = []
        
        for pr in prerequisites:
            sub = pr[0]
            neigh = pr[1]
            adj_list[sub].append(neigh)
        # print(f"adj_list: {adj_list}")
            
        indegres = {node: 0 for node in adj_list}
        for n in adj_list:
            for neigh in adj_list[n]:
                indegres[neigh] += 1
        # print(f"indegres: {indegres}")
        
        top_order = []
        indegres_zeros = []
        
        for n in indegres:
            if indegres[n] == 0:
                indegres_zeros.append(n)
                
        while len(indegres_zeros) > 0:
            node = indegres_zeros.pop()
            top_order.append(node)
            for neigh in adj_list[node]:
                indegres[neigh] -= 1
                if indegres[neigh] == 0:
                    indegres_zeros.append(neigh)
        
        if len(top_order) == len(adj_list):
            return True
        else:
            return False
