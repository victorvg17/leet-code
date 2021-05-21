
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # if len(prerequisites) == 0:
        #     return [0]
        adj_list = {i: [] for i in range(numCourses)}
        for pr in prerequisites:
            sub, pre_req = pr[0], pr[1]
            adj_list[sub].append(pre_req)
        print(f"adj_list: {adj_list}")
        
        indegrees = {node: 0 for node in adj_list}
        for node in adj_list:
            for neigh in adj_list[node]:
                indegrees[neigh] += 1
        print(f"indegrees: {indegrees}")
        
        top_order = []
        indegr_zeros = []
        for node in indegrees:
            if indegrees[node] == 0:
                indegr_zeros.append(node)
                
        while len(indegr_zeros) > 0:
            curr_node =  indegr_zeros.pop()
            top_order.append(curr_node)
            for neigh in adj_list[curr_node]:
                indegrees[neigh] -= 1
                if indegrees[neigh] == 0:
                    indegr_zeros.append(neigh)
        
        if len(top_order) == len(adj_list):
            return top_order[::-1]
        else:
            return []
        
