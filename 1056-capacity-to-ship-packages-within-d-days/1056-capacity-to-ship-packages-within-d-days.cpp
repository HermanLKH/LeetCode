#include <algorithm> 

class Solution {
public:
    int possibleCapacity(int capacity, int daysAvailable, vector<int>& weights) {
        int daysNeeded = 1;
        int dayWeight = 0;
        int i = 0;

        // exceeds days available, break the loop
        while (daysNeeded <= daysAvailable) {
            // loop over all indexes = completes all cargo
            if (i == weights.size()) {
                return true;
            }
            // if still can ship more cargo on the same day
            if (weights[i] + dayWeight <= capacity) {
                // update the accummulated weight of the day
                dayWeight = dayWeight + weights[i];
                // update index of cargo only if it is loaded
                i = i + 1;
            }
            // exceeds the maximum capacity of the day
            else {
                // reset the accummulated weight of the day
                dayWeight = 0;
                daysNeeded = daysNeeded + 1;
            }
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int L = 0;
        int H = 0;
        int M;

        for (int weight: weights) {
            L = max(L, weight);
            H = H + weight;
        }

        while (L < H) {
            M = L + (H - L) / 2;

            if (possibleCapacity(M, days, weights)) {
                H = M;
            }
            else {
                L = M + 1;
            }
        }
        return H;
    }
};