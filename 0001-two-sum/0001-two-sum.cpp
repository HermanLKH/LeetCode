class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int num1;
        int num2;
        vector<int> ans;

        for (int x = 0; x < nums.size(); ++x) {
            num1 = nums[x];

            for (int y = 0; y < nums.size() && y != x; ++y) {
                num2 = nums[y];

                if (num1 + num2 == target) {
                    ans.push_back(x);
                    ans.push_back(y);
                    return ans;
                }
            }
        }
        return ans;
    }
};