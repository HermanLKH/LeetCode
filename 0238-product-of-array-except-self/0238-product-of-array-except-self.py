class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total_products = 1
        has_zero = False
        has_zeroes = False

        for num in nums:
            if num != 0:
                total_products *= num
            else:
                if not has_zero:
                    has_zero = True 
                elif not has_zeroes:
                    has_zeroes = True  

        ans = []

        for num in nums:
            if has_zeroes:
                ans.append(0)
            elif has_zero:
                if num == 0:
                    ans.append(int(total_products))
                else:
                    ans.append(0)
            else:
                ans.append(int(total_products / num))
                
        return ans
