class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer = {} # val: index
        for index, val in enumerate(nums):
            diff = target - val
            if diff in answer:
                return [answer[diff], index]
            answer[val] = index
