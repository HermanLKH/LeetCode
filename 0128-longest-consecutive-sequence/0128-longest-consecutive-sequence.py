class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        # O(n log n)    
        sorted_nums = sorted(nums)
        current_num = sorted_nums[0]
        longest_consec_count = 1
        curr_consec_count = 1
        # O(n)
        for i in range(1, len(sorted_nums), 1):
            next_num = sorted_nums[i]

            if current_num + 1 == next_num:
                curr_consec_count += 1
                
                if curr_consec_count > longest_consec_count:
                    longest_consec_count = curr_consec_count

            elif current_num == next_num:
                continue

            else:
                curr_consec_count = 1
            
            current_num = next_num

        return longest_consec_count