class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> seen(nums.size() + 1, false);
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            seen[nums[i]] = true;
        }
        
        for (int i = 1; i <= nums.size(); ++i) {
            if (!seen[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};