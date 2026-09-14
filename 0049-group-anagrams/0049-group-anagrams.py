class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        all_empty = all(s == "" for s in strs)

        if all_empty:
            return [strs]
        
        patterns, groups, counts = {}, [], {}

        for i, s in enumerate(strs):
            patterns[s] = {}
            counts[s] = counts.get(s, 0) + 1

            for c in s:
                patterns[s][c] = patterns[s].get(c, 0) + 1
        
        grouped_str = {}

        for s, str_pattern in patterns.items():
            for s2, str_pattern2 in patterns.items():
                if str_pattern == str_pattern2 and not grouped_str.get(s2, False):
                    if s == s2:
                        groups.append([])

                    for _ in range(counts.get(s2, 1)):
                        groups[-1].append(s2)
                        
                    grouped_str[s2] = True

        return groups        
