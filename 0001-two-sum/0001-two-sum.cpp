class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // number, index
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // calculate difference between selected number and target
            int diff = target - nums[i];
            
            // check if the difference number exist
            if (seen.count(diff)) {
                // if same element found -> ignore
                if (seen[diff] != i) {
                    return vector<int>{i, seen[diff]};
                }
            }
        }
        return vector<int>{};
    }
};