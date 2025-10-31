class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        }

        vector<int> ans = {0, 1};
        
        for (int i = 0; i < (int) log2(n); ++i) {
            int ansSize = ans.size();

            for (int j = 0; j < ansSize; ++j) {
                if (ans.size() < n + 1) {
                    ans.push_back(ans[j] + 1);
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};