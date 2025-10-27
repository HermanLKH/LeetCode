class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0;
        int R = nums.size() - 1;
        int M;

        // if target is smaller than smallest value
        if (nums[L] > target) {
            return L;
        }
        // if target is greater than greatest value
        else if (nums[R] < target) {
            return R + 1;
        }

        while (L < R) {
            M = L + (R - L) / 2;
            
            if (nums[M] == target) {
                return M;
            }
            else if (nums[M] < target) {
                L = M + 1;
            }
            else {
                R = M; 
            }
        }
        return R;
    }
};