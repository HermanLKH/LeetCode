class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        countNums = {}

        for num in nums:
            if num in countNums:
                return True
            else:
                countNums[num] = 1
        
        return False