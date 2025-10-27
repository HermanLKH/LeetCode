class Solution {
public:
    int mySqrt(int x) {
        // if x = 0 or 1, x is the answer
        if (x < 2) {
            return x;
        }
        
        // if x >= 2
        int l = 1;  // smallest answer starts from 1
        int r = x / 2;  // greatest answer never smaller than (divide by 2 + 1)
        int m;
        long long sq;

        while (l <= r) {
            m = l + (r - l) / 2;

            sq = 1LL * m * m;

            if (sq == x) {
                return m;
            }
            else if (sq < x) {
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return r;
    }
};