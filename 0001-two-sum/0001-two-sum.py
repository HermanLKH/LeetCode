class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        seenNums = {}

        for i, num in enumerate(nums):
            diff = target - num

            if diff in seenNums:
                return [seenNums[diff], i]
            
            seenNums[num] = i
