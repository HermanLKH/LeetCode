class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if len(digits) == 0:
            return None

        digits[-1] += 1

        for i in range(len(digits) - 1, -1, -1):
            if digits[i] == 10:
                digits[i] = 0

                if (i - 1) == -1:
                    digits.insert(0, 1)
                    return digits
                else:
                    digits[i - 1] += 1
            else:
                return digits