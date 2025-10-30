class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNum = 0;

        for (int n: nums) {
            singleNum ^= n;
        }

        return singleNum ^ 0;
    }
};