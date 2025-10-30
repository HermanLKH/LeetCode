class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        vector<bool> seen(size, false);

        for (int n: nums) {
            seen[n] = true;
        }

        for (int i = 0; i <= size; ++i) {
            if (!seen[i]) {
                return i;
            }
        }
        return -1;
    }
};