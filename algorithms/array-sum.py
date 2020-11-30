class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        answer = [None]*2
        for i in range(len(nums)-1):
            answer[0] = i
            for j in range(i+1, len(nums)):
                if nums[answer[0]] + nums[j] == target:
                    answer[1] = j
                    return answer
