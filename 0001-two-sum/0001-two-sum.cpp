class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // number, index
        unordered_map<int, int> valueToIndex;

        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            // calculate difference between selected number and target
            int diff = target - currentNum;
            
            // check if the difference number exist
            if (valueToIndex.count(diff)) {
                // if same element found -> ignore
                return vector<int>{i, valueToIndex[diff]};
            }
            valueToIndex[currentNum] = i;
        }
        return vector<int>{};
    }
};