class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            sol = target - nums[i]
            for j in range(i+1, len(nums)):
                if sol == nums[j]:
                    return [i, j]