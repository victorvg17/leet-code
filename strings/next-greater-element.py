
class Solution:
    def list_to_num(self, lst: List[int]) -> int:
        ret = 0
        for i, n in enumerate(lst[::-1]):
                ret += (10**i) * n
        return ret
        
    def nextGreaterElement(self, n: int) -> int:
        n_str = str(n)
        n_list = list(map(int, n_str))
        l = len(n_list)
        if n_list == sorted(n_list, reverse=True):
            return -1
        
        i=l-1
        while (i>0):
            if n_list[i-1] < n_list[i]:
                smallest = i
                x = n_list[i-1]
                break
            i -= 1
        
        
        for j in range(i+1, l):
            if n_list[j] > x and n_list[j] <= n_list[smallest]:
                smallest = j
        
        # swap elements at turn_idx and smallest_idx
        temp = n_list[i-1]
        n_list[i-1] = n_list[smallest]
        n_list[smallest] = temp
        
        #sort elements after i-1
        ret = n_list[:i] + sorted(n_list[i:])
        print(f"ret: {ret}")
        ret = self.list_to_num(ret)
        return -1 if ret > (2**31) - 1 else ret
