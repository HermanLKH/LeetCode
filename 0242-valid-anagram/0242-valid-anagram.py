class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        charCount = {}

        for charS in s:
            charCount[charS] = charCount.get(charS, 0) + 1

        for charT in t:
            if charT not in charCount or charCount[charT] == 0:
                return False
            charCount[charT] -= 1

        return True  
