class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.reserve(n + 1);  
        ans.push_back(0);  
        
        for (size_t i = 0; i < (size_t) log2(n + 1) + 1; ++i) {
            size_t ansSize = ans.size();

            for (size_t j = 0; j < ansSize; ++j) {
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