class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        n = len(nums)
        start, end = 0, n-1
        while start <= end:
            mid = (start + end) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                start = mid + 1
            else:
                end = mid - 1
        return end + 1
