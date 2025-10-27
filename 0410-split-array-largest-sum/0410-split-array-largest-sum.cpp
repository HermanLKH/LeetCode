class Solution {
public:
    int possibleSum(int maxSum, int k, vector<int>& nums) {
        int numOfSubArray = 0;
        int sumOfSubArray = 0;
        int i = 0;

        // exceeds days available, break the loop
        while (numOfSubArray < k) {
            // loop over all indexes = completes all cargo
            if (i == nums.size()) {
                return true;
            }
            // if still can ship more cargo on the same day
            if (nums[i] + sumOfSubArray <= maxSum) {
                // update the accummulated weight of the day
                sumOfSubArray = sumOfSubArray + nums[i];
                // update index of cargo only if it is loaded
                i = i + 1;
            }
            // exceeds the maximum capacity of the day
            else {
                // reset the accummulated weight of the day
                sumOfSubArray = 0;
                numOfSubArray = numOfSubArray + 1;
            }
        }
        return false;
    }
 
    int splitArray(vector<int>& nums, int k) {
        int H = 0;
        int L = 0;
        int M;

        for(int num: nums) {
            if (num > H) {
                L = num;
            }
            H = H + num;
        }

        while (L < H) {
            M = L + (H - L) / 2;

            if (possibleSum(M, k, nums)) {
                H = M;
            }
            else {
                L = M + 1;
            }
        }
        return H;
    }
};