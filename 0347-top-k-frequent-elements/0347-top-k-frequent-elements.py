class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count_nums = {}

        for num in nums:
            count_nums[num] = count_nums.get(num, 0) + 1

        sorted_count_nums = dict(sorted(count_nums.items(), key=lambda item: item[1], reverse=True))
        ans = []

        for num, count in sorted_count_nums.items():
            if k > 0:
                ans.append(num)
                k -= 1
        
        return ans