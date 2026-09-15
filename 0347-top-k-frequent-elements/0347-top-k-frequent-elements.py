class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if len(nums) == k:
            return nums

        count_nums = Counter(nums)

        return heapq.nlargest(k, count_nums.keys(), key=count_nums.get)
